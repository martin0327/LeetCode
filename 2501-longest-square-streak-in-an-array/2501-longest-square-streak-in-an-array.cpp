class Solution {
public:
  int longestSquareStreak(vector<int>& a) {
    using ll = long long;
    sort(a.rbegin(), a.rend());
    int n = a.size();
    map<ll,ll> mp;
    for (int i=0; i<n; i++) {
      ll x = a[i];
      if (mp.count(x*x)) mp[x] = max(mp[x], mp[x*x] + 1);
      else mp[x] = 1;
    }
    ll ans = -1;
    for (auto &[k,v] : mp) {
      if (v>1) ans = max(ans,v);
    }
    return ans;
  }
};