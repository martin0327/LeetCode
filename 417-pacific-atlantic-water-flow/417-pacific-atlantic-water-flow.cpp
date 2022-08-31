using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi dr = {0,-1,0,1};
vi dc = {1,0,-1,0};

class Solution {
public:
  
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    
    queue<pii> q;
    vvi check1(n, vi(m));
    vvi check2 = check1;
    
    for (int i=0; i<n; i++) {
      q.push({i,0});
      check1[i][0] = 1;
    }
    for (int j=1; j<m; j++) {
      q.push({0,j});
      check1[0][j] = 1;
    }
    
    while (q.size()) {
      auto [r,c] = q.front();
      q.pop();
      for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= n) continue;
        if (nc < 0 || nc >= m) continue;
        if (a[nr][nc] < a[r][c]) continue;
        if (check1[nr][nc]) continue;
        check1[nr][nc] = 1;
        q.push({nr,nc});
      }
    }
    
    for (int i=0; i<n; i++) {
      q.push({i,m-1});
      check2[i][m-1] = 1;
    }
    for (int j=0; j<m-1; j++) {
      q.push({n-1,j});
      check2[n-1][j] = 1;
    }
    
    while (q.size()) {
      auto [r,c] = q.front();
      q.pop();
      for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= n) continue;
        if (nc < 0 || nc >= m) continue;
        if (a[nr][nc] < a[r][c]) continue;
        if (check2[nr][nc]) continue;
        check2[nr][nc] = 1;
        q.push({nr,nc});
      }
    }
    vvi ans;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (check1[i][j] && check2[i][j]) ans.push_back({i,j});
      }
    }
    return ans;
    
  }
};