using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<ll> dp(n,1);
        unordered_map<ll,ll> mp;
        for (int i=0; i<n; i++) mp[a[i]] = i;
        for (int i=0; i<n; i++) {
          for (int j=0; j<i; j++) {
              if (a[i] % a[j] == 0) {
                  if (mp.count(a[i]/a[j])) {
                      dp[i] += dp[j] * dp[mp[a[i]/a[j]]];
                      dp[i] %= mod;
                  }
              }
          }
        }
        ll ans = 0;
        for (int i=0; i<n; i++) {
          ans += dp[i];
          ans %= mod;
        }
        return ans;
    }
};