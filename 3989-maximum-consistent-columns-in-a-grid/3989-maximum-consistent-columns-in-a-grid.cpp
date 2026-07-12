template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& a, int lim) {
        int n = a.size(), m = a[0].size();
        vvi b(m, vi(m));
        for (int j=0; j<m; j++) {
            for (int i=0; i<j; i++) {
                b[i][j] = 1;
                for (int r=0; r<n; r++) {
                    auto x = a[r][i], y = a[r][j];
                    if (abs(x-y) > lim) {
                        b[i][j] = 0;
                        break;
                    }
                }
            }
        }
        vi dp(m);
        iota(dp.begin(), dp.end(), 0);
        for (int j=1; j<m; j++) {
            for (int i=0; i<j; i++) {
                if (b[i][j]) {
                    chmin(dp[j], dp[i]+(j-i-1));
                }
            }
        }
        auto ans = dp.back();
        for (int i=0; i<m; i++) {
            chmin(ans, dp[i] + (m-1-i));
        }
        ans = m - ans;
        return ans;
    }
};