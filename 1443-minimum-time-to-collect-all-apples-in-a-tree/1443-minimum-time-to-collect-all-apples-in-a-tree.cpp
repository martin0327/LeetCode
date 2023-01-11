using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  int n;
  vvi adj;
  int ans = 0;
  bool f(int u, int p, vector<bool> &a) {
    bool ret = false;
    for (auto v : adj[u]) {
      if (v==p) continue;
      if (f(v,u,a)) {
        ans += 2;
        ret = true;
      }
    }
    return ret | a[u];
  }
  int minTime(int _n, vector<vector<int>>& edges, vector<bool>& a) {
    n = _n;
    adj = vvi(n);
    for (auto uv : edges) {
      int u = uv[0];
      int v = uv[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    f(0,-1,a);
    return ans;
  }
};