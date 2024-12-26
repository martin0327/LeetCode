using vi = vector<int>;
class Solution {
public:
    int findTargetSumWays(vector<int>& a, int tg) {
        int n = a.size(), m = 0;
        for (auto x : a) m += x;
        m = max(m, abs(tg));
        
        vi dp(2*m+1);
        dp[m] = 1;
        for (auto x : a) {
            vi ndp(2*m+1);
            for (int i=0; i<=2*m; i++) {   
                vi nb = {i-x, i+x};
                for (auto j : nb) {
                    if (0 <= j && j <= 2*m) {
                        ndp[j] += dp[i];
                    }
                }
            }
            swap(dp,ndp);
        }        
        return dp[tg+m];      
    }
};