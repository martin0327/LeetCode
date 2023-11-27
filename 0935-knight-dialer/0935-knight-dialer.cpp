using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int knightDialer(int n) {
        int m = 9;
        vvi adj = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vi dp1(m+1,1), dp2;
        while (--n) {
            dp2.assign(m+1,0);
            for (int i=0; i<=m; i++) {
                for (auto j : adj[i]) {
                    dp2[j] += dp1[i];
                    dp2[j] %= mod;
                }
            }
            swap(dp1,dp2);
        }
        ll ans = 0;
        for (auto x : dp1) {
            ans += x;
            ans %= mod;
        }
        return ans;
    }
};