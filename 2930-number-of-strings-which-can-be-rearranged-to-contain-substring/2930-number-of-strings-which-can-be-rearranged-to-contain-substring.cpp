using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int stringCount(int n) {
        vector dp1(2, vvi(2, vi(3)));
        vector dp2 = dp1;
        dp1[0][0][0] = 1;
        for (int i=0; i<n; i++) {
            dp2 = dp1;
            for (auto &x : dp2) for (auto &y : x) for (auto &z : y) z = 0;
            
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    for (int l=0; l<3; l++) {
                        int nj = min(1,j+1);
                        int nk = min(1,k+1);
                        int nl = min(2,l+1);
                        dp2[j][k][l] += 23 * dp1[j][k][l];
                        dp2[j][k][l] %= mod;
                        dp2[nj][k][l] += dp1[j][k][l];
                        dp2[nj][k][l] %= mod;
                        dp2[j][nk][l] += dp1[j][k][l];
                        dp2[j][nk][l] %= mod;
                        dp2[j][k][nl] += dp1[j][k][l];
                        dp2[j][k][nl] %= mod;
                    }
                }
            }
            swap(dp1,dp2);
        }
        ll ans = dp1[1][1][2];
        return ans;
    }
};