using ti3 = tuple<int,int,int>;
using vi = vector<int>;
const int inf = 1e9;
vi dr = {0,-1,0,1};
vi dc = {1,0,-1,0};

class Solution {
public:
  int dist[40][40][1600];
  
  int shortestPath(vector<vector<int>>& a, int k) {
    int n = a.size();
    int m = a[0].size();
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        for (int l=0; l<=k; l++) {
          dist[i][j][l] = inf; 
        }
      }
    }
    dist[0][0][0] = 0;
    queue<ti3> q;
    q.emplace(0,0,0);

    while (q.size()) {
      auto [r,c,e] = q.front(); q.pop();
      for (int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nr >= n) continue;
        if (nc < 0 || nc >= m) continue;

        if (a[nr][nc]) {
          if (e >= k) continue;
          if (dist[nr][nc][e+1] > dist[r][c][e]+1) {
            dist[nr][nc][e+1] = dist[r][c][e]+1;
            q.emplace(nr,nc,e+1);
          }
        }
        else {
          if (dist[nr][nc][e] > dist[r][c][e]+1) {
            dist[nr][nc][e] = dist[r][c][e]+1;
            q.emplace(nr,nc,e);
          }
        }
      }    
    }
    int ans = inf;
    for (int l=0; l<=k; l++) ans = min(ans, dist[n-1][m-1][l]);
    if (ans==inf) ans = -1;
    return ans;
  }
};