template<typename T>
void chmax(T &x, T y) {x = max(x,y);}

class Solution {
public:
  int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pf) {
    map<int,int> mp;
    for (auto x : st) mp[x] = 0;
    for (auto x : et) mp[x] = 0;
    int m = 1;
    for (auto &[k,v] : mp) v = m++;
    int n = st.size();
    vector<vector<pair<int,int>>> a(m);
    for (int i=0; i<n; i++) {
      int s = mp[st[i]];
      int e = mp[et[i]];
      int x = pf[i];
      a[e].push_back({s,x});
    }
    vector<int> dp(m);
    for (int i=1; i<m; i++) {
      chmax(dp[i],dp[i-1]);
      for (auto &[j,x] : a[i]) chmax(dp[i],dp[j]+x);
    }
    return dp[m-1];
  }
};