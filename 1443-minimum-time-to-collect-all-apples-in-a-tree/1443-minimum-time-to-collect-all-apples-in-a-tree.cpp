using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  int n;
  vvi adj;
  vector<bool> a;
  pii f(int u, int p) {
    int x = 0, y = 0;
    for (auto v : adj[u]) {
      if (v==p) continue;
      auto [dx, dy] = f(v,u);
      if (dy) x += 2;
      y |= dy;
      x += dx;
    }
    return {x,y|a[u]};
  }
  int minTime(int _n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    n = _n;
    a = hasApple;
    adj = vvi(n);
    for (auto uv : edges) {
      int u = uv[0];
      int v = uv[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    return f(0,-1).first;
  }
};