using ll = long long;
const ll inf = 2e15;
class Solution {
public:
    int change(int k, vector<int>& c) {
        int n = c.size();
        vector<ll> dp(k+1);
        dp[0] = 1;
        for (ll i=0; i<n; i++) {
            for (ll j=0; j<=k; j++) {
                int nj = j + c[i];
                if (nj > k) break;
                dp[nj] += dp[j];
                dp[nj] = min(dp[nj], inf);
            }
        }
        return dp[k];
    }
};