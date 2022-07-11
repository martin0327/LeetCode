template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
  }
};

template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
  int minCost(vector<int>& _a, vector<vector<int>>& _b, int n, int m, int target) {
    vi a(n+1);
    for (int i=1; i<=n; i++) a[i] = _a[i-1];

    vvi b(n+1, vi(m+1));
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
        b[i][j] = _b[i-1][j-1];
      }
    }

    const ll inf = 1e18;

    Vec<3, ll> dp(n+1, m+2, n+1, inf);
    dp[0][m+1][0] = 0;
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
        for (int k=0; k<i; k++) {
          for (int l=0; l<=m+1; l++) {
            if (a[i] == 0) {
              if (j==l) dp[i][j][k] = min(dp[i][j][k], dp[i-1][l][k] + b[i][j]);
              else dp[i][j][k+1] = min(dp[i][j][k+1], dp[i-1][l][k] + b[i][j]);
            }          
            else if (a[i] == j) {
              if (j==l) dp[i][j][k] = min(dp[i][j][k], dp[i-1][l][k]);
              else dp[i][j][k+1] = min(dp[i][j][k+1], dp[i-1][l][k]);
            }
          }
        }
      }
    }
    
    ll ans = inf;
    for (int j=1; j<=m; j++) {
      ans = min(ans, dp[n][j][target]);
    }
    if (ans==inf) ans = -1;
    return ans;
  }
};