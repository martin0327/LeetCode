using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
class Solution {
public:
  int numEnclaves(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    vvi v(n, vi(m));
    queue<pii> q;
    vi dr = {0,0,-1,1}, dc = {-1,1,0,0};
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (!a[i][j] || v[i][j]) continue;
        v[i][j] = 1;
        q.emplace(i,j);
        bool ok = false;
        int cnt = 1;
        while (q.size()) {
          auto [r,c] = q.front();
          q.pop();
          for (int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
              ok = true;
              continue;
            }
            if (!a[nr][nc]) continue;
            if (v[nr][nc]) continue;
            cnt++;
            q.emplace(nr,nc);
            v[nr][nc] = 1;
          }
        }
        if (!ok) ans += cnt;
      }
    }
    return ans;
  }
};