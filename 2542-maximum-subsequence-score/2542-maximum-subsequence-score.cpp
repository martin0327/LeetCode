using ll = long long;
using ti3 = tuple<ll,ll,ll>;

class Solution {
public:
  long long maxScore(vector<int>& a, vector<int>& b, int k) {

    ll n = a.size();
    set<ti3> s1, s2;
    vector<ti3> c(n), d(n);
    for (int i=0; i<n; i++) {
      c[i] = {a[i],b[i],i};
      d[i] = {b[i],a[i],i};
    }
    sort(c.rbegin(), c.rend());
    for (int i=0; i<k-1; i++) s1.insert(c[i]);
    for (int i=k-1; i<n; i++) s2.insert(c[i]);
    ll ans = 0;
    sort(d.begin(), d.end());

    ll s = 0;
    for (auto [x,y,i] : s1) s += x;

    for (auto t : d) {
      auto [y,x,i] = t;
      if (s1.count({x,y,i})) {
        s1.erase({x,y,i});
        s -= x;
      }
      if (s2.count({x,y,i})) s2.erase({x,y,i});
      while (s1.size() < k-1 && s2.size()) {
        auto [x,y,i] = *prev(s2.end());
        s2.erase({x,y,i});
        s1.insert({x,y,i});
        s += x;
      }
      if (s1.size() == k-1) ans = max(ans, y*(s+x));
      else break;
    }
    return ans;
  }
};