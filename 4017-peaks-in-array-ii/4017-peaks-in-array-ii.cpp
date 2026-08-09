
#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace atcoder;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

ll f(ll x) {
    return x*(x+1)/2;
}

struct S {
    ll cnt, len, tot, left, right;
};
S op(S x, S y) {
    S ret;
    ll cnt = x.cnt + y.cnt;
    ll len = x.len + y.len;
    if (cnt == 0) {
        ret = {cnt,len,0,0,0};
    }
    else if (x.cnt == 0) {
        ll tot = y.tot;
        ll left = x.len + y.left;
        ll right = y.right;
        ret = {cnt,len,tot,left,right};
    }
    else if (y.cnt == 0) {
        ll tot = x.tot;
        ll left = x.left;
        ll right = x.right + y.len;
        ret = {cnt,len,tot,left,right};
    }
    else {
        ll tot = x.tot + y.tot + f(x.right+y.left+2);
        ll left = x.left;
        ll right = y.right;
        ret = {cnt,len,tot,left,right};
    }
    return ret;
}

S e() { S ret = {0,0,0,0,0}; return ret; }

class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& aa, vector<vector<int>>& qr) {
        vi a(aa.begin(), aa.end());
        ll n = a.size();
        vi b(n);
        set<ll> s;
        for (int i=1; i+1<n; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                b[i] = 1;
                s.insert(i);
            }
        }
        vector<S> init(n);
        for (int i=0; i<n; i++) {
            if (b[i]) init[i] = {1,1,0,0,0};
            else init[i] = {0,1,0,0,0};
        }
        segtree<S,op,e> seg(init);
        vector<ll> ans;
        for (auto &v : qr) {
            ll t = v[0];
            if (t == 1) {
                ll l = v[1], r = v[2];
                auto res = seg.prod(l,r+1);
                if (res.cnt == 0) {
                    ans.push_back(0);
                }
                else {
                    auto it1 = s.lower_bound(l);
                    auto it2 = s.upper_bound(r);
                    ll tot = res.tot - res.cnt;
                    if (it1 != s.end()) {
                        tot += f(*it1-l+1);
                    }
                    if (it2 != s.begin()) {
                        tot += f(r-*prev(it2)+1);
                    }
                    ans.push_back(f(r-l+1) - tot);
                }
            }
            else {
                ll idx = v[1], val = v[2];
                a[idx] = val;
                for (int i=idx-1; i<=idx+1; i++) {
                    if (i<0 || i>=n ) continue;
                    if (i > 0 && i+1 < n) {
                        if (a[i] > a[i-1] && a[i] > a[i+1]) {
                            seg.set(i, {1,1,0,0,0});
                            s.insert(i);
                        }
                        else {
                            seg.set(i,{0,1,0,0,0});
                            if (s.count(i)) s.erase(i);
                        }
                    }
                    else {
                        seg.set(i,{0,1,0,0,0});
                        if (s.count(i)) s.erase(i);
                    }
                }

            }
        }
        return ans;
    }
};