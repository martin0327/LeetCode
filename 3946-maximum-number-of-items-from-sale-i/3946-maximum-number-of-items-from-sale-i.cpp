template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
const int inf = 2e9;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& a, int k) {
        int n = a.size();
        vi b(n);
        for (int i=0; i<n; i++) {
            int x = a[i][0];
            for (int j=0; j<n; j++) {
                if (j == i) continue;
                int y = a[j][0];
                if (y % x == 0) b[i]++;
            }
        }
        vi dp(k+1,-inf);
        dp[0] = 0;
        for (int i=0; i<n; i++) {
            int y = a[i][1];
            for (int j=k; j>=y; j--) {
                if (dp[j-y] == -inf) continue;
                chmax(dp[j], dp[j-y]+b[i]+1);
            }
            for (int j=y; j<=k; j++) {
                if (dp[j-y] == -inf) continue;
                chmax(dp[j], dp[j-y]+1);
            }
        }
        auto ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};