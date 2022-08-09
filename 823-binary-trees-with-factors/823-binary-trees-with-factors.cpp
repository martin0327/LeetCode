using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        int n = a.size();
        vector<ll> b;
        for (int &x : a) b.push_back(x);
        sort(b.begin(), b.end());
        vector<ll> dp(n,1);
        unordered_map<ll,ll> mp;
        for (int i=0; i<n; i++) mp[b[i]] = i;
        for (int i=0; i<n; i++) {
          for (int j=0; j<i; j++) {
              if (b[i] % b[j] == 0) {
                  if (mp.count(b[i]/b[j])) {
                      dp[i] += dp[j] * dp[mp[b[i]/b[j]]];
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