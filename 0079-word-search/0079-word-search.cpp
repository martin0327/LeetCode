using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  vi dr = {0,-1,0,1};
  vi dc = {1,0,-1,0};
  int n,m;
  string s;
  vector<vector<char>> a;
  vvi check;
  
  bool f(int r, int c, int i) {
    if (i == s.size()-1 && a[r][c] == s[i]) return true;
    if (a[r][c] != s[i]) return false;
    check[r][c] = 1;
    
    bool ret = false;
    for (int d=0; d<4; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= n) continue;
      if (nc < 0 || nc >= m) continue;
      if (check[nr][nc]) continue;
      ret |= f(nr,nc,i+1);
    }    
    check[r][c] = 0;
    return ret;
  }
  
  bool exist(vector<vector<char>>& board, string word) {
    a = board;
    s = word;    
    n = a.size();
    m = a[0].size();
    check = vvi(n, vi(m));
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (f(i,j,0)) return true;
      }
    }
    return false;
  }
};