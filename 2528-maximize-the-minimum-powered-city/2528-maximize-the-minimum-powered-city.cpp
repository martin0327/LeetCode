template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += T(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

using ll = long long;

class Solution {
public:
  long long maxPower(vector<int>& a, int r, int k) {
    ll n = a.size();    
    ll lo = 0, hi = 2e10, ans = -1;

    while (lo <= hi) {
      ll mid = (lo + hi) / 2;
      fenwick_tree<ll> fen(n);
      for (ll i=0; i<n; i++) fen.add(i, a[i]);
      ll cnt = 0;
      for (ll i=0; i<n; i++) {
        ll llim = max(0ll, i - r);
        ll rlim = min(n-1, i + r);
        ll s = fen.sum(llim,rlim+1);
        ll d = max(0ll, mid - s);
        fen.add(rlim,d);
        cnt += d;
        if (cnt > k) break;
      }
      if (cnt <= k) {
        ans = mid;
        lo = mid + 1;
      }
      else hi = mid - 1;
    }
    return ans;
  }
};  