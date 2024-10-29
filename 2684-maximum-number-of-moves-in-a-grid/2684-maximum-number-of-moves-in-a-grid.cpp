const int inf = 1e9;
using vi = vector<int>;
using vvi = vector<vi>;

vi dr = {-1,0,1};
vi dc = {-1,-1,-1};

class Solution {
public:
    int maxMoves(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;
        vvi dp(n, vi(m, -inf));
        for (int i=0; i<n; i++) dp[i][0] = 0;
        for (int j=1; j<m; j++) {
            for (int i=0; i<n; i++) {
                for (int d=0; d<3; d++) {
                    int r = i + dr[d];
                    int c = j + dc[d];
                    if (r < 0 || r>= n) continue;
                    if (a[i][j] > a[r][c]) {
                        dp[i][j] = max(dp[i][j], dp[r][c] + 1);
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};