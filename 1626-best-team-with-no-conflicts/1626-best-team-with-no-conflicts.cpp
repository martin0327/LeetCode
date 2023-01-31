template<typename T> void chmax(T &x, T y) {x = max(x,y);}
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  int bestTeamScore(vector<int>& a, vector<int>& b) {
    int n = a.size();
    map<int,int> mp;
    int sz = 0;
    for (auto x : a) mp[x];
    for (auto &[k,v] : mp) v = sz++;
    vti3 c(n);
    for (int i=0; i<n; i++) c[i] = {b[i], mp[a[i]], a[i]};
    sort(c.begin(), c.end());

    vvi dp(n+1, vi(sz));
    for (int i=0; i<n; i++) {
      auto [y,z,x] = c[i];
      dp[i+1] = dp[i];
      for (int j=0; j<sz; j++) {
        if (z >= j) chmax(dp[i+1][z],dp[i][j] + x);
      }
    }
    int ans = *max_element(dp[n].begin(), dp[n].end());
    return ans;
  }     
};      