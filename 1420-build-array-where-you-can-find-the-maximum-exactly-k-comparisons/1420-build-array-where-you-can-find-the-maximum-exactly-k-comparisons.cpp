using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vvi dp1(m+1, vi(n+1));
        vvi dp2 = dp1;
        dp1[0][0] = 1;
        for (int i=0; i<n; i++) {
            dp2 = vvi(m+1, vi(n+1));
            for (int j=0; j<=m; j++) {
                for (int l=0; l<=i; l++) {
                    if (dp1[j][l] == 0) continue;
                    for (int h=1; h<=m; h++) {
                        if (h > j) {
                            dp2[h][l+1] += dp1[j][l];
                            dp2[h][l+1] %= mod;
                        }
                        else {
                            dp2[j][l] += dp1[j][l];
                            dp2[j][l] %= mod;
                        }
                    }
                }
            }
            swap(dp1,dp2);
        }
        ll ans = 0;
        for (int j=0; j<=m; j++) {
            ans += dp1[j][k];
            ans %= mod;
        }
        return ans;
    }
};