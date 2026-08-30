using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 2e9;
void chmin(int &x, int y) { x = min(x,y); }
void debug(vi &a) {
    for (auto x : a) {
        cout << x << " ";
    }   cout << endl;
}

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int n = a.size();
        vvi dp(n+1, vi(k+1, inf));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=k; j++) {
                if (dp[i][j] == inf) continue;
                chmin(dp[i+1][j], dp[i][j]);
                int x = a[i];
                if (j+x <= k) chmin(dp[i+1][j+x], dp[i][j]);
                for (int l=1;x>0;l++) {
                    x /= 2;
                    if (j+x <= k) {
                        chmin(dp[i+1][j+x], dp[i][j]+l);
                    }
                }
                x = a[i];
                for (int l=1; ; l++) {
                    x *= 2;
                    if (j+x <= k) {
                        chmin(dp[i+1][j+x], dp[i][j]+l);
                    }
                    else break;
                }
            }
            // debug(dp[i+1]);
        }
        auto ans = dp[n][k];
        if (ans == inf) ans = -1;
        return ans;
    }
};