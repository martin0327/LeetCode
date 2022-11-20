using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll mod = 1e9+7;

class Solution {
public:
  int beautifulPartitions(string s, int K, int minLength) {
    ll n = s.size();
    ll ml = minLength;
    vi primes = {2,3,5,7};
    vi is_prime(10);
    for (auto p : primes) is_prime[p] = 1;
    vi a(n+1);
    for (int i=1; i<=n; i++) a[i] = s[i-1] - '0';

    vvi dp(K+1, vi(n+1));
    dp[0][0] = 1;
    for (int k=0; k<K; k++) {
      vi cum(n+1);
      for (int i=0; i<n; i++) {
        if (is_prime[a[i+1]]) {
          if (i+ml <= n) {
            cum[i+ml] += dp[k][i];
            cum[i+ml] %= mod;
          }
        }
      }
      for (int i=1; i<=n; i++) {
        cum[i] += cum[i-1];
        cum[i] %= mod;
        if (!is_prime[a[i]]) dp[k+1][i] = cum[i];
      }
    }
    ll ans = dp[K][n];
    return ans;
  }
};