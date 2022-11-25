using ll = long long;
using pii = pair<ll,ll>;
const ll mod = 1e9+7;

class Solution {
public:
  int sumSubarrayMins(vector<int>& a) {
    int n = a.size();
    vector<pii> b(n);
    for (int i=0; i<n; i++) b[i] = {a[i],i};
    sort(b.begin(), b.end());
    set<int> s;
    ll ans = 0;
    for (auto [x,i] : b) {
      auto it = s.lower_bound(i);
      int l,r;
      if (it==s.end()) r = n;
      else r = *it;
      if (it==s.begin()) l = -1;
      else l = *prev(it);
      ans += x * (r-i) * (i-l);
      ans %= mod;
      s.insert(i);
    }
    return ans;
  }
}; 