using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  int n;
  vvi adj;
  vector<bool> a;
  int ans = 0;
  bool f(int u, int p) {
    bool ret = a[u];
    for (auto v : adj[u]) {
      if (v==p) continue;
      if (f(v,u)) {
        ans += 2;
        ret = true;
      }
    }
    return ret;
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
    f(0,-1);
    return ans;
  }
};