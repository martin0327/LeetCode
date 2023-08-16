
#include <algorithm>
#include <cassert>
#include <tuple>
#include <vector>


#include <utility>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    unsigned long long im;

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    unsigned int umod() const { return _m; }

    unsigned int mul(unsigned int a, unsigned int b) const {

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

long long pow_mod(long long x, long long n, int m) {
    assert(0 <= n && 1 <= m);
    if (m == 1) return 0;
    internal::barrett bt((unsigned int)(m));
    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
    while (n) {
        if (n & 1) r = bt.mul(r, y);
        y = bt.mul(y, y);
        n >>= 1;
    }
    return r;
}

long long inv_mod(long long x, long long m) {
    assert(1 <= m);
    auto z = internal::inv_gcd(x, m);
    assert(z.first == 1);
    return z.second;
}

std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }


        long long g, im;
        std::tie(g, im) = internal::inv_gcd(m0, m1);

        long long u1 = (m1 / g);
        if ((r1 - r0) % g) return {0, 0};

        long long x = (r1 - r0) / g % u1 * im % u1;

        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

}  // namespace atcoder

using namespace atcoder;



using ll = long long;
using vi = vector<ll>;




class Solution {
public:
    
    vi primes;
    vi spf; 
    void init_spf(int n) {
        spf.resize(n+1);
        for (int i=2; i <= n; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; i * primes[j] <= n; j++) {
                spf[i * primes[j]] = primes[j];
                if (primes[j] == spf[i]) {
                    break;
                }
            }
        }
    }

    vi get_pfactors(int x) {
        vector<ll> ret;
        while (x != 1) {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        vi a;
        for (auto x : nums) a.push_back(x);
        ll n = a.size();
        init_spf(1e5+1);
        vector<pair<ll,ll>> b(n);
        for (ll i=0; i<n; i++) {
            vi temp = get_pfactors(a[i]);
            ll sz = set<ll>(temp.begin(), temp.end()).size();
            b[i] = {-sz,i};
        }
        sort(b.begin(), b.end());
        set<ll> s;
        vi l(n), r(n);
        for (auto [x,idx] : b) {
            auto it = s.lower_bound(idx);
            if (it == s.end()) r[idx] = n-1;
            else r[idx] = *it-1;
            if (it == s.begin()) l[idx] = -1;
            else l[idx] = *prev(it);
            s.insert(idx);
        }
        vector<pair<ll,ll>> c(n);
        // debug(a);
        // debug(l);
        // debug(r);
        for (int i=0; i<n; i++) {
            c[i] = {a[i], (r[i]-i+1) * (i-l[i])};
        }
        sort(c.rbegin(), c.rend());
        // debug(c);
        ll ans = 1;
        const ll mod = 1e9+7;
        for (auto [x,cnt] : c) {
            if(k==0) break;
            ll d = min(cnt,(ll)k);
            k -= d;
            ll y = pow_mod(x,d,mod);
            ans *= y;
            ans %= mod;
        }
        return ans;
    }
};