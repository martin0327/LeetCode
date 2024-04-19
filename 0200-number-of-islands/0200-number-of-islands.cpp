using vi = vector<int>;
using vvi = vector<vi>;
vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi visited(n, vi(m));

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j]==1) continue;
                if (grid[i][j] == '0') continue;

                ans++;
                queue<pair<int,int>> que;
                que.push({i,j});
                visited[i][j] = 1;
                while (!que.empty()) {
                    auto [r,c] = que.front();
                    que.pop();
                    for (int k=0; k<4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr < 0 || nr >= n) continue;
                        if (nc < 0 || nc >= m) continue;
                        if (visited[nr][nc]==1) continue;
                        if (grid[nr][nc] == '0') continue;
                        visited[nr][nc] = 1;
                        que.push({nr,nc});
                    }
                }
            }
        }
        return ans;
    }
};