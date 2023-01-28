const int inf = 1e9;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& b) {

    int n = b.size();
    vvi a = vvi(n, vi(n));
    {
      int idx = 1;
      bool right = true;
      for (int i=n-1; i>=0; i--) {
        if (right) {
          for (int j=0; j<n; j++) {
            a[i][j] = idx++;
          }
        }
        else {
          for (int j=n-1; j>=0; j--) {
            a[i][j] = idx++;
          }
        }
        right ^= 1;
      }
    }
    map<int,pii> i2c;
    map<pii,int> c2i;

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        i2c[a[i][j]] = {i,j};
        c2i[{i,j}] = a[i][j];
      }
    }

    queue<int> q;
    vi dist(n*n+1, inf);
    q.push(1);
    dist[1] = 0;
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i=1; i<=6; i++) {
        int v = min(n*n, u+i);
        auto [r,c] = i2c[v];
        if (b[r][c] != -1) v = b[r][c];
        if (dist[v] == inf) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    int ans = dist[n*n];
    if (ans == inf) ans = -1;
    return ans;
  
  }
};