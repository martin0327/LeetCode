using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
vi dr = {0,-1,0,1};
vi dc = {-1,0,1,0};

class Solution {
public:
    int numIslands(vector<vector<char>>& a) {
        
        int n = a.size();
        int m = a[0].size();
                
        vvi check(n, vi(m));
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '0') continue;
                if (check[i][j]) continue;
                
                ans++;
                queue<pii> q;
                q.push({i,j});
                check[i][j] = 1;
                
                while (q.size()) {
                    auto [r,c] = q.front();
                    q.pop();
                    for (int d=0; d<4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr<0 || nr>=n) continue;
                        if (nc<0 || nc>=m) continue;
                        if (a[nr][nc] == '0') continue;
                        if (check[nr][nc]) continue;
                        q.push({nr,nc});
                        check[nr][nc] = 1;
                    }
                }
            }
        }
        return ans;
    }
};