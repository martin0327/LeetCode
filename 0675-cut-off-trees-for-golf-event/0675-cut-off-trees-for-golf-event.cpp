using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
const int inf = 2e9;
vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};
class Solution {
public:
    int cutOffTree(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        auto oob = [&] (int r, int c) {
            if (r < 0 || r >= n) return true;
            if (c < 0 || c >= m) return true;
            return false;
        };

        int sz = n*m;
        vvi dist(sz, vi(sz,inf));
        auto f = [&] (int sr, int sc) {
            vvi vis(n, vi(m,inf));
            vis[sr][sc] = 0;
            queue<pii> q;
            q.push({sr,sc});
            while (q.size()) {
                auto [r,c] = q.front();
                q.pop();
                for (int i=0; i<4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (oob(nr,nc)) continue;
                    if (a[nr][nc] == 0) continue;
                    if (vis[nr][nc] < inf) continue;
                    vis[nr][nc] = vis[r][c] + 1;
                    q.push({nr,nc});
                }
            }
            int src = m*sr + sc;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (vis[i][j] == inf) continue;
                    int tg = m*i + j;
                    dist[src][tg] = vis[i][j];
                }
            }
        };
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) f(i,j);
            }
        }
        vp b;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int pos = m*i+j;
                int w = a[i][j];
                if (w > 1) {
                    b.push_back({w,pos});
                }
            }
        }
        sort(b.begin(), b.end());
        int ans = 0, cur = 0;
        for (auto [w,pos] : b) {
            if (dist[cur][pos] == inf) {
                ans = inf;
                break;
            }
            ans += dist[cur][pos];
            cur = pos;
        }
        if (ans == inf) ans = -1;
        return ans;
    }
};