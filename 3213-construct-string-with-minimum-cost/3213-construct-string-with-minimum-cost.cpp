template<typename T>
void chmax(T &x, T y) {x = max(x,y);}

template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  

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

long long pow_mod(long long x, long long n, int m) {
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

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using ti3 = tuple<ll,ll,ll>;
using vs = vector<string>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

const ll inf = 2e18;

struct rabin_karp {
    int n,p,m;
    vi p_pow,p_inv,h;

    rabin_karp(string s, int p, int m) {
        this->n = s.size();
        this->p = p;
        this->m = m;
        p_pow = p_inv = vi(n+1,1);
        for (int i=1; i<=n; i++) p_pow[i] = (p_pow[i-1]*p)%m;
        p_inv[n] = pow_mod(p_pow[n],m-2,m);
        for (int i=n-1; i>0; i--) p_inv[i] = (p_inv[i+1]*p)%m;
        h = vi(n+1);
        for (int i=0; i<n; i++) {
            int x = ('a'<=s[i] && s[i]<='z') ? (s[i]-'a'+1) : (s[i]-'A'+27);
            h[i+1] = (h[i]+(x*p_pow[i]))%m;
        }
    }

    int query(int l, int r) {
        assert(0<=l && l<=r && r<n);
        int x = ((h[r+1]-h[l])%m+m)%m;
        return (x*p_inv[l]) % m;
    }
};


class Solution {
public:
    int minimumCost(string tg, vector<string>& a, vector<int>& c) {
        ll n = tg.size();
        ll m = a.size();

        vi dp(n+1,inf);
        dp[0] = 0;

        ll mx_sz = 0;
        vi lens;
        for (auto s : a) {
            ll sz = s.size();
            lens.push_back(sz);
            chmax(mx_sz, sz);
        }
        lens = get_unique(lens);

        ll p1 = 677, p2 = 757;
        ll m1 = 1e9+7, m2 = 998244353;

        vi hash(m);
        unordered_map<ll,ll> mp;
        for (int i=0; i<m; i++) {
            auto s = a[i];
            ll sz = s.size();
            rabin_karp rk1(s,p1,m1);
            hash[i] = rk1.query(0,sz-1);
            if (!mp.count(hash[i])) mp[hash[i]] = c[i];
            else chmin(mp[hash[i]], (ll) c[i]);
        }

        rabin_karp rk1(tg,p1,m1);

        for (int i=1; i<=n; i++) {
            for (auto len : lens) {
                ll l = i - len;
                ll r = i - 1;
                if (l < 0) break;
                ll h1 = rk1.query(l,r);
                ll key = h1;
                if (mp.count(key)) {
                    chmin(dp[i], dp[i-len] + mp[key]);
                }
            }
        }

        ll ans = dp[n];
        if (ans == inf) ans = -1;
        return ans;

        
    }
};