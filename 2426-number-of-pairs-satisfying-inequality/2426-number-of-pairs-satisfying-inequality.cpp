template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += x;
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
  long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
    int n = a.size();
    vector<ll> c(n);
    for (int i=0; i<n; i++) {
      c[i] = a[i] - b[i];
    }
    
    ll min_c = 1e18;
    for (auto x : c) min_c = min(min_c,x);
    for (auto &x : c) x -= min_c;
    
    fenwick_tree<ll> fw(1e5);
    ll ans = 0;

    for (auto x : c) {
      ll r = x + diff + 1;
      if (r >= 0) ans += fw.sum(0,r);
      fw.add(x,1);
    }
    return ans;
  }
};