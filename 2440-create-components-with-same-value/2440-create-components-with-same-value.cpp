using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  int componentValue(vector<int>& a, vector<vector<int>>& edges) {
    int n = a.size();
    vvi adj(n);
    for (auto uv : edges) {
      int u = uv[0], v = uv[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int tot = accumulate(a.begin(), a.end(), 0);
    int ans = 0;

    function<bool(int)> f = [&](int x) {
      vi deg(n), b = a;
      queue<int> q;
      for (int i=0; i<n; i++) {
        deg[i] = adj[i].size();
        if (deg[i]==1) q.push(i);
      }
      int cnt = 0;
      
      while (q.size()) {
        int u = q.front(); q.pop();
        deg[u]--;
        if (b[u] == x) cnt++;
        for (auto v : adj[u]) {
          if (deg[v] == 0) continue;
          if (b[u] < x) b[v] += b[u];
          if (--deg[v]==1) q.push(v);
        }
      }
      return cnt == tot / x;
    };

    for (int i=1; i*i<=tot; i++) {
      if (tot % i == 0) {
        int x = i;
        int y = tot / i;
        if (f(x)) ans = max(ans, y-1);
        if (f(y)) ans = max(ans, x-1);
      }
    }
    return ans;
  }
};