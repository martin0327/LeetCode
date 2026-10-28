using vi = vector<int>;
using vvi = vector<vi>;
const int mx_sz = 1e3+1;
vi vis[mx_sz][mx_sz];
vi dr = {0,1};
vi dc = {1,0};
class Solution {
public:
    int minCost(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int sz = 1<<11;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                vis[i][j] = vi(sz);
                // for (int l=0; l<sz; l++) {
                //     vis[i][j][l] = 0;
                // }
            }
        }
        vis[0][0][a[0][0]] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int l=0; l<sz; l++) {
                    if (!vis[i][j][l]) continue;
                    for (int d=0; d<2; d++) {
                        int r = i + dr[d];
                        int c = j + dc[d];
                        if (r >=n || c >= m) continue;
                        int nl = l ^ a[r][c];
                        vis[r][c][nl] = 1;
                    }
                }
            }
        }
        int ans = sz;
        for (int l=0; l<sz; l++) {
            if (vis[n-1][m-1][l]) ans = min(ans, l);
        }
        return ans;
    }
};