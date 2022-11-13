using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:

  int n;
  int k;
  string s;
  vvi palin;
  vi dp;

  bool is_palin(int i, int j) {
    if (palin[i][j] != -1) return palin[i][j];
    if (j-i < 1) return palin[i][j] = true;
    bool ret = (s[i] == s[j]);
    ret &= is_palin(i+1,j-1);
    return palin[i][j] = ret;
  }

  int f(int i) {
    if (i+k-1>=n) return 0;
    if (dp[i] != -1) return dp[i];
    int ret = 0;
    for (int j=i+k-1; j<n; j++) {
      if (is_palin(i,j)) ret = max(ret, 1+f(j+1));
    }
    ret = max(ret, f(i+1));
    return dp[i] = ret;
  }

  int maxPalindromes(string _s, int _k) {
    s = _s;
    k = _k;
    n = s.size();
    palin = vvi(n, vi(n, -1));
    dp = vi(n, -1);
    int ans = f(0);

    return ans;
  }
};