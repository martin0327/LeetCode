using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;

class Solution {
public:
  int n;
  vvi adj;
  vi ans;
  vp a;
  
  pii f(int u, int p) {
    int x = 0;
    int y = 1;
    for (auto v : adj[u]) {
      if (v==p) continue;
      auto [z,w] = f(v,u);
      x += z + w;
      y += w;
    }
    return a[u] = {x,y};
  }

  void g(int u, int p) {
    auto [x,y] = a[u];
    ans[u] = x;
    for (auto v : adj[u]) {
      if (v==p) continue;
      auto &[z,w] = a[v];
      z += x - (z+w) + (n-w);
      g(v,u);
    }
  }
  
  vector<int> sumOfDistancesInTree(int _n, vector<vector<int>>& edges) {
    n = _n;
    ans = vi(n);
    adj = vvi(n);
    a = vp(n);
    
    for (auto uv : edges) {
      int u = uv[0];
      int v = uv[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    f(0,-1);
    g(0,-1);
    return ans;
  }
};        