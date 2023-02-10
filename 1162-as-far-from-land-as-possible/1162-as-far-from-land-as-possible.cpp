using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
vi dr = {0,-1,0,1};
vi dc = {1,0,-1,0};

class Solution {
public:
  int maxDistance(vector<vector<int>>& a) {
    queue<pii> q;
    int n = a.size();
    vvi dist(n, vi(n, -1));
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (a[i][j]) {
          q.emplace(i,j);
          dist[i][j] = 0;
        }
      }
    }
    int sz = q.size();
    if (sz==n*n || sz==0) return -1;
    
    int ans = 0;
    while(q.size()) {
      auto [r,c] = q.front();
      q.pop();
      for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= n) continue;
        if (nc < 0 || nc >= n) continue;
        if (dist[nr][nc]==-1) {
          q.emplace(nr,nc);
          dist[nr][nc] = dist[r][c] + 1;
          ans = max(ans, dist[nr][nc]);
        }
      }
    }
    return ans;
  }
};