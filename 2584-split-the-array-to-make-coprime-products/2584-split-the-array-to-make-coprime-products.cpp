
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

using vi = vector<int>;
using vvi = vector<vi>;

// vvi pfactors;
// vi primes;
// vi is_prime;
// void init_primes(int n) {
//   pfactors.resize(n+1);
//   is_prime.resize(n+1);
//   for (int i=2; i<=n; i++) {
//     if (pfactors[i].empty()) {
//       is_prime[i] = 1;
//       primes.push_back(i);
//       for (int j=i; j<=n; j+=i) {
//         pfactors[j].push_back(i);
//       }
//     }
//   }
// }
vi spf; // smallest prime factor
void init_spf(int n) {
  spf.resize(n+1);
  spf[1] = 1;
  for (int i=2; i<=n; i++) spf[i] = i;
  for (int i=4; i<=n; i+=2) spf[i] = 2;
  for (int i=3; i*i<=n; i++) {
    if (spf[i] == i) {
      for (int j=i*i; j<=n; j+=i) {
        if (spf[j]==j) spf[j] = i;
      }
    }
  }
}

vi get_prime_factors(int x) {
  vector<int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}

int op(int a, int b) {
  return max(a, b);
}

int e() {
  return 0;
}

class Solution {
public:
  int findValidSplit(vector<int>& a) {
      int n = a.size();
      int mx = 1e6;
      init_spf(mx);
      map<int,int> l,r;
      for (auto x : a) {
        for (auto p : get_prime_factors(x)) {
          while (x % p == 0) {
            x /= p;
            r[p]++;
          }
        }
      }
      segtree<int, op, e> seg(mx+1);
      for (int i=0; i<n-1; i++) {
        int x = a[i];
        for (auto p : get_prime_factors(x)) {
          while (x % p == 0) {
            x /= p;
            l[p]++;
            r[p]--;
          }
          seg.set(p,min(l[p],r[p]));
        }
        if (seg.all_prod()==0) return i;
      }
      return -1;

  }
};