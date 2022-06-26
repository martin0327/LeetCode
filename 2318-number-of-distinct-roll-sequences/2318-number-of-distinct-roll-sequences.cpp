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

const int mod = 1e9+7;

class Solution {
public:
  int distinctSequences(int n) {
    if (n==1) return 6;
    Vec<3,int> dp(n+1,7,7);
    for (int i=1; i<=6; i++) {
      for (int j=1; j<=6; j++) {
        if (i==j) continue;
        if (__gcd(i,j)==1) dp[2][i][j] = 1;
      }
    }
    for (int i=3; i<=n; i++) {
      for (int j=1; j<=6; j++) {
        for (int k=1; k<=6; k++) {
          if (__gcd(j,k) != 1) continue;
          if (j==k) continue;
          for (int l=1; l<=6; l++) {
            if (l==k) continue;
            if (__gcd(l,j) != 1) continue;
            dp[i][j][k] += dp[i-1][l][j];
            dp[i][j][k] %= mod;
          }
        }
      }
    }
    long long ans = 0;
    for (int i=1; i<=6; i++) {
      for (int j=1; j<=6; j++) {
        ans += dp[n][i][j];
          ans %= mod;
      }
    }

    return ans;
  }
};