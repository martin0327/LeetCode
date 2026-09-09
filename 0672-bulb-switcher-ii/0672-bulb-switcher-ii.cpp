using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int flipLights(int n, int k) {
        auto f = [&] (int sz, vi tr) {
            vi vis(sz,sz);
            vvi dp(k+1, vi(sz));
            dp[0][0] = 1;
            for (int i=0; i<k; i++) {
                for (int j=0; j<sz; j++) {
                    if (!dp[i][j]) continue;
                    for (auto t : tr) {
                        int nj = j ^ t;
                        dp[i+1][nj] = 1;
                    }
                }
            }
            int ans = 0;
            for (int j=0; j<sz; j++) {
                ans += dp[k][j];
            }
            return ans;
        };
        if (n == 1) {
            vi tr = {0,1};
            auto ans = f(2,tr);
            return ans;
        }
        else if (n == 2) {
            vi tr = {1,2,3};
            auto ans = f(4,tr);
            return ans;
        }
        else if (n == 3) {
            vi tr = {1,2,5,7};
            auto ans = f(8,tr);
            return ans;
        }
        else {
            vi tr = {3,6,9,15};
            auto ans = f(16,tr);
            return ans;
        }
    }
};