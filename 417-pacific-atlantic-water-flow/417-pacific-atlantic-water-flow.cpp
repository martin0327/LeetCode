template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using pii = pair<int,int>;
using ti3 = tuple<int,int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
vi dr = {0,-1,0,1};
vi dc = {1,0,-1,0};


class Solution {
public:
  int n,m;  
  vvi a, dp1, dp2, visited1, visited2;
  
  int f(int r, int c, vvi &visited, vvi &dp, bool flag) {
    // debug(r,c);
    visited[r][c]++;
    if (dp[r][c] != 0) return dp[r][c];
    if (flag) {
      if (r==n-1 || c==m-1) return dp[r][c] = 1;
    }
    else {
      if (r==0 || c==0) return dp[r][c] = 1;
    }

    int ret = 0;
    for (int d=0; d<4; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      // if (r==18 && c==3) {
      //   debug(flag);
      //   debug(r,c);
      //   debug(nr,nc);
      //   debug(f(nr,nc,visited,dp,flag));
      // }
      if (nr<0 || nr>=n) continue;
      if (nc<0 || nc>=m) continue;
      if (a[nr][nc] > a[r][c]) continue;
      // if (visited[nr][nc]) {
      //   if (dp[nr][nc]==1) ret = 1;
      // }
      // else {
      //   if (f(nr,nc,visited,dp,flag)==1) ret = 1; 
      // } 
      if (visited[nr][nc]>2) {
        if (dp[nr][nc]==1) ret = 1;
      }
      else {
        if (f(nr,nc,visited,dp,flag)==1) ret = 1; 
      }

    }
    // if (r==18 && c==4) {
    //   debug(r,c);
    //   debug(ret);
    //   debug(flag);
    // }
    return dp[r][c] = ret;
  }
  
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& aa) {
    a = aa;
    n = a.size();
    m = a[0].size();
    
    dp1 = vvi(n, vi(m));
    visited1 = visited2 = dp2 = dp1;
    
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (visited1[i][j]==0) f(i,j,visited1,dp1,0);
        if (visited2[i][j]==0) f(i,j,visited2,dp2,1);
      }
    }
    
    vvi ans;    
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (dp1[i][j]==1 && dp2[i][j]==1) ans.push_back({i,j});
      }
    }
    
    return ans;    
  }
};