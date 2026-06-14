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


template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

const int inf = 2e9;
using vi = vector<int>;
using S = int;
S op(S x, S y) { return x + y; }
S e() { return 0; }
using segt = segtree<S, op, e>;
segt b1, b2, in1, in2, out1, out2;
vi cp;

class Solution {
public:
    long long maxSum(vector<int>& a, int k) {
        int n = a.size();
        if (n == 0) return 0;

        cp = get_unique(a);
        auto sz = cp.size();
        
        auto g = [&](int x) {
            auto it = lower_bound(cp.begin(), cp.end(), x);
            return it - cp.begin();
        };
        
        for (auto &x : a) x = g(x);
        
        b1 = segt(sz); 
        b2 = segt(sz);
        for (int i = 0; i < n; i++) {
            auto x = a[i];
            b1.set(x, b1.get(x) + 1);
            b2.set(x, b2.get(x) + cp[x]);
        }

        int ans = -inf;
        
        for (int i = 0; i < n; i++) {
            in1 = segt(sz); 
            in2 = segt(sz);
            out1 = b1;      
            out2 = b2;
            
            auto f1 = [&](segt &seg1, segt &seg2, int cnt) {
                auto r = seg1.max_right(0, [&](int x) {
                    return x < cnt;
                });
                assert(r < sz);
                int s = seg2.prod(0, r);
                s += (cnt - seg1.prod(0, r)) * cp[r];
                return make_pair(r, s);
            };

            auto f2 = [&](segt &seg1, segt &seg2, int cnt) {
                auto l = seg1.min_left(sz, [&](int x) {
                    return x < cnt;
                });
                int s = seg2.prod(l, sz);
                if (l - 1 >= 0) {
                    s += (cnt - seg1.prod(l, sz)) * cp[l - 1];
                }
                return make_pair(l, s);
            };

            int best_c = 0; 

            for (int j = i; j < n; j++) {
                auto x = a[j];
                in1.set(x, in1.get(x) + 1);
                in2.set(x, in2.get(x) + cp[x]);
                out1.set(x, out1.get(x) - 1);
                out2.set(x, out2.get(x) - cp[x]);
                
                int c = min({k, in1.all_prod(), out1.all_prod(), best_c + 1});
                int diff = 0;
                
                while (c > 0) {
                    auto [i1, s1] = f1(in1, in2, c);
                    auto [i2, s2] = f2(out1, out2, c);
                    
                    if (i1 <= i2) { 
                        diff = s2 - s1;
                        break; 
                    }
                    c--;
                }
                
                best_c = c; 
                chmax(ans, in2.all_prod() + diff);
            }
            
            // b1.set(a[i], b1.get(a[i]) - 1);
            // b2.set(a[i], b2.get(a[i]) - cp[a[i]]);
        }
        return ans;
    }
};