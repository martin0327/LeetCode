template <class T> struct fenwick_tree {
  using U = T;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

using ll = long long;
using vi = vector<ll>;

class Solution {
public:
  int countRangeSum(vector<int>& a, int lower, int upper) {
    ll n = a.size();
    ll lo = lower;
    ll hi = upper;

    ll cum = 0;
    map<ll,ll> mp;
    mp[0] = 0;
    for (auto x : a) mp[cum+=x] = 0;
    ll sz = 0;
    for (auto &[k,v] : mp) v = sz++;
    fenwick_tree<ll> fw(sz);
    fw.add(mp[0],1);

    ll ans = 0;
    cum = 0;
    for (auto x : a) {
      cum += x;
      int l=-1, r=-1;
      auto it = mp.lower_bound(cum - hi);
      if (it != mp.end()) l = (*it).second;
      it = mp.upper_bound(cum - lo);
      if (it != mp.begin()) r = (*prev(it)).second;
      if (l != -1 && r != -1) {
        ans += fw.sum(l,r+1);
      }
      fw.add(mp[cum],1);
    }
    return ans;
  }
};