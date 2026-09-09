using vi = vector<int>;
using vvi = vector<vi>;
const int mxk = 1000;
bool dp[5][mxk+1][17];
bool done = false;
class Solution {
public:
    int flipLights(int n, int k) {
        if (!done) {
            done = true;
            for (int l=1; l<=4; l++) {
                int sz = 1<<l;
                vi tr;
                if (l == 1) tr = {0,1};
                else if (l == 2) tr = {1,2,3};
                else if (l == 3) tr = {1,2,5,7};
                else tr = {3,6,9,15};
                dp[l][0][0] = 1;
                for (int i=0; i<mxk; i++) {
                    for (int j=0; j<sz; j++) {
                        if (!dp[l][i][j]) continue;
                        for (auto t : tr) {
                            int nj = j ^ t;
                            dp[l][i+1][nj] = 1;
                        }
                    }
                }
            }
        }
        auto f = [&] (int n) {
            n = min(n, 4);
            int ans = 0, sz = 1<<n;
            for (int j=0; j<sz; j++) {
                ans += dp[n][k][j];
            }
            return ans;
        };
        return f(n);
    }
};