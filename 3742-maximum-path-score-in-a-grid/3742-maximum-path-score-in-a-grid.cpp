template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

using vi = vector<int>;
const vi dr = {0,1};
const vi dc = {1,0};
const int inf = 2e9;

int dp[201][201][1005];

class Solution {
public:
    int maxPathScore(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int l=0; l<=k; l++) {
                    dp[i][j][l] = -inf;
                }
            }
        }
        dp[0][0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int l=0; l<=k; l++) {
                    if (dp[i][j][l] == -inf) continue;
                    for (int d=0; d<2; d++) {
                        int nr = i + dr[d];
                        int nc = j + dc[d];
                        if (nr >= n || nc >= m) continue;
                        int nl = l;
                        if (a[nr][nc] != 0) nl++;
                        if (nl > k) continue;
                        chmax(dp[nr][nc][nl], dp[i][j][l] + a[nr][nc]);
                    }
                }
            }
        }
        int ans = -inf;
        for (int l=0; l<=k; l++) {
            chmax(ans, dp[n-1][m-1][l]);
        }
        if (ans == -inf) ans = -1;
        return ans;
    }
};