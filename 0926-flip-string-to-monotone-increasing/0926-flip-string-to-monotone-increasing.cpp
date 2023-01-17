class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int n = s.size();
      vector<int> pre(n+1);
      for (int i=1; i<=n; i++) pre[i] = pre[i-1] + (s[i-1] == '0');
      int ans = 1e9;
      for (int i=0; i<=n; i++) {
        int x = i - pre[i];
        int y = pre[n] - pre[i];
        ans = min(ans, x+y);
      }
      return ans;
    }
};  