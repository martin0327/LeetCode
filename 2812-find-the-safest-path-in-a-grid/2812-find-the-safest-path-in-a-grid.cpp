using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
const int inf = 2e9;

vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& a) {
        int n = a.size();
        queue<pii> q;
        vvi b(n, vi(n,inf));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j]) {
                    b[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        auto check = [&] (int r, int c) {
            return (r>=0 && r<n && c>=0 && c<n);
        };
        while (q.size()) {
            auto [r,c] = q.front(); q.pop();
            for (int d=0; d<4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (!check(nr,nc)) continue;
                if (b[nr][nc] < inf) continue;
                b[nr][nc] = b[r][c] + 1;
                q.push({nr,nc});
            }
        }
        
        auto dbg = [&] (vvi &a) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    cout << a[i][j] << " ";
                }   cout << endl;
            }
        };
        
        auto bfs = [&] (int lim) {
            vvi vis(n, vi(n));
            queue<pii> q;
            if (b[0][0] < lim) return 0;
            q.push({0,0});
            vis[0][0] = 1;
            while (q.size()) {
                auto [r,c] = q.front();
                q.pop();
                for (int d=0; d<4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (!check(nr,nc)) continue;
                    if (vis[nr][nc]) continue;
                    if (b[nr][nc]<lim) continue;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
            return vis[n-1][n-1];
        };
        
        int lo = 0, hi = 2*n, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (bfs(mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};