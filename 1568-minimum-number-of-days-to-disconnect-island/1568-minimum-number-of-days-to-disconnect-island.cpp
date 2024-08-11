using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;


vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};

class Solution {
public:
    int minDays(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        
        
        auto check = [&] (int r, int c) {
            if (r < 0 || r >= n) return false;
            if (c < 0 || c >= m) return false;
            return true;
        };
        
        {
            vvi vis(n, vi(m));
            int cnt = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (a[i][j] && !vis[i][j]) {
                        cnt++;
                        vis[i][j] = 1;
                        queue<pii> q;
                        q.push({i,j});
                        while (q.size()) {
                            auto [r,c] = q.front();
                            q.pop();
                            for (int d=0; d<4; d++) {
                                int nr = r + dr[d];
                                int nc = c + dc[d];
                                if (!check(nr,nc)) continue;
                                if (!a[nr][nc]) continue;
                                if (vis[nr][nc]) continue;
                                q.push({nr,nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
            cout << cnt << endl;
            if (cnt != 1) return 0;
        }
        
        

        int tot = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) tot++;
            } 
        }
        
        
        
        int ans = tot;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) {
                    int cnt = 1;
                    for (int d=0; d<4; d++) {
                        int r = i + dr[d];
                        int c = j + dc[d];
                        if (!check(r,c)) continue;
                        if (a[r][c]) cnt++;
                    }
                    if (tot - cnt > 0) {
                        ans = min(ans, cnt-1);
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) {
                    vvi vis(n, vi(m));
                    vis[i][j] = 1;
                    for (int d=0; d<4; d++) {
                        int r = i + dr[d];
                        int c = j + dc[d];
                        if (!check(r,c)) continue;
                        if (a[r][c]) {
                            int cnt = 2;
                            vis[r][c] = 1;
                            queue<pii> q;
                            q.push({r,c});
                            while (q.size()) {
                                auto [r,c] = q.front();
                                q.pop();
                                for (int d=0; d<4; d++) {
                                    int nr = r + dr[d];
                                    int nc = c + dc[d];
                                    if (!check(nr,nc)) continue;
                                    if (vis[nr][nc]) continue;
                                    if (!a[nr][nc]) continue;
                                    cnt++;
                                    vis[nr][nc] = 1;
                                    q.push({nr,nc});
                                } 
                            }
                            if (tot - cnt > 1) ans = 1;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// [1,0,1,1,1]
// [0,1,1,1,1]
// [0,1,1,1,1]
// [1,1,1,1,1]
// [1,0,1,0,1]
// [0,1,1,1,1]
// [0,1,0,0,1]
// [1,1,1,0,1]
