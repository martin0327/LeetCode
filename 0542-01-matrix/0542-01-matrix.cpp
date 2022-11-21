using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
const int inf = 1e9;

vi dr = {0,-1,0,1};
vi dc = {1,0,-1,0};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        vvi dist(n, vi(m, inf));
        queue<pii> q;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while (q.size()) {
            auto [r,c] = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                if (dist[nr][nc] != inf) continue;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }
        return dist;
    }
};