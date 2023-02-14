class Solution {
public:
  int maximizeWin(vector<int>& a, int k) {
    int n = a.size();
    map<int,int> mp;
    for (int i=0; i<n; i++) {
      int x = a[i];
      auto it = upper_bound(a.begin(), a.end(), x+k);
      mp[x] = max(mp[x], (int) (it - a.begin()) - i);
    }
    
    map<int,int> suf;
    {
      set<int> s(a.begin(), a.end());
      vector<int> b(s.begin(), s.end());
      reverse(b.begin(), b.end());
      int cur = 0;
      for (auto x : b) {
        cur = max(cur, mp[x]);
        suf[x] = cur;
      }
    }
    
    suf[2e9+1] = 0;
    int ans = 0;
    for (auto [x,v] : mp) {
      auto it = suf.upper_bound(x+k);
      ans = max(ans, v + it->second);
    }
    return ans;
  }
};