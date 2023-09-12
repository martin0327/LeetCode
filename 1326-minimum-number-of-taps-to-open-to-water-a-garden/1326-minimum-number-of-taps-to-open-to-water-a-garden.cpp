using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
    int minTaps(int n, vector<int>& rg) {
        vvi a(n+1);
        for (int i=0; i<=n; i++) {
            int l = max(0,i - rg[i]);
            int r = min(n,i + rg[i]);
            a[r].push_back(l);
        }
        vi dp(n+1, inf);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (auto l : a[i]) {
                for (int j=l; j<i; j++) {
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return (dp[n]==inf) ? -1 : dp[n];
    }
};