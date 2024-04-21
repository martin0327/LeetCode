using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int sz = 10;
        const ll inf = 1e9;
        vvi dp(m+1, vi(sz+1,inf));
        dp[0][sz] = 0;
        for (int j=0; j<m; j++) {
            vi cnt(sz);
            for (int i=0; i<n; i++) {
                cnt[a[i][j]]++;
            }
            for (int l=0; l<=sz; l++) {
                if (dp[j][l] == inf) continue;
                for (int nl=0; nl<sz; nl++) {
                    if (l==nl) continue;
                    int x = 0;
                    for (int i=0; i<sz; i++) {
                        if (i != nl) x += cnt[i];
                    }
                    dp[j+1][nl] = min(dp[j+1][nl],dp[j][l]+x);
                }
            }
        }
        ll ans = inf;
        for (int l=0; l<sz; l++) ans = min(ans, dp[m][l]);
        return ans;
    }
};