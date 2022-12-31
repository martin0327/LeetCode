using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const vi dr = {0,-1,0,1};
const vi dc = {1,0,-1,0};

class Solution {
public:
  int uniquePathsIII(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();

    int s,t;
    int done = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (a[i][j] == 1) s = i*m+j;
        if (a[i][j] == 2) t = i*m+j;
        if (a[i][j] != -1) done |= 1<<(i*m + j);
      }
    }

    vvi dp(n*m, vi(1<<(n*m)));
    dp[s][1<<s] = 1;
    queue<pii> q;
    q.emplace(s,1<<s);

    while (q.size()) {
      auto [u,mask] = q.front();
      q.pop();
      int r = u/m, c = u%m;
      for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        int v = nr*m+nc;
        if (nr < 0 || nr >= n) continue;
        if (nc < 0 || nc >= m) continue;
        if (a[nr][nc] == -1) continue;
        if (mask>>v&1) continue;
        int nmask = mask | (1<<v);
        if (dp[v][nmask] == 0) q.emplace(v,nmask);
        dp[v][nmask] += dp[u][mask];
      }
    }
    return dp[t][done];
  }
};