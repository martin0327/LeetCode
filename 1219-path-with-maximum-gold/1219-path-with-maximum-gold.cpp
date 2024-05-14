const int inf = 1e9;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;
        vvi vis(n, vi(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) {
                    int cur = 0;
                    function<void(int,int)> f = [&] (int r, int c) {
                        cur += a[r][c];
                        ans = max(ans, cur);
                        for (int d=0; d<4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            if (nr < 0 || nr >= n) continue;
                            if (nc < 0 || nc >= m) continue;
                            if (!a[nr][nc]) continue;
                            if (vis[nr][nc]) continue;
                            vis[nr][nc] = 1;
                            f(nr,nc);
                            vis[nr][nc] = 0;
                        }
                        cur -= a[r][c];
                    };
                    vis[i][j] = 1;
                    f(i,j);
                    vis[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
