class Solution {
public:
    
    vector<int> dp;
    vector<int> a;
    int n;
    
    bool f(int i) {
  if (i==n) return true;
  if (i>n) return false;
  if (dp[i] != -1) return dp[i];
  bool ret = 0;
  if (i+1 < n && a[i]==a[i+1]) {
    if (f(i+2)==1) ret = 1;
  }
  if (i+2 < n && a[i]==a[i+1] && a[i]==a[i+2]) {
    if (f(i+3)==1) ret = 1;
  }
  if (i+2 < n && a[i]+1==a[i+1] && a[i+1]+1==a[i+2]) {
    if (f(i+3)==1) ret = 1;
  }
  return dp[i] = ret;
}
    
    bool validPartition(vector<int>& _a) {
          a = _a;
          n = a.size();
          dp = vector<int>(n,-1);
          int ans = f(0);
          if (ans==1) return 1;
          else return false;
        
    }
};