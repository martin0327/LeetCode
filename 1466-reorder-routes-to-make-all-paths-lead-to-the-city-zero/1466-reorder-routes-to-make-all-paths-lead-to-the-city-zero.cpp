using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  vvi adj;
  vector<set<int>> check;
  int ans = 0;
  void f(int u, int p) {
    for (auto v : adj[u]) {
      if (v==p) continue;
      if (check[u].count(v)) ans++;
      f(v,u);
    }
  }
  
  int minReorder(int n, vector<vector<int>>& c) {
    adj = vvi(n);
    check = vector<set<int>>(n);
    for (auto uv : c) {
      int u = uv[0], v = uv[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      check[u].insert(v);
    }
    f(0,-1);
    return ans;
  }
};