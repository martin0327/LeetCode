using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int,int>;
const int inf = 1e9;

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
    vvvi adj(n, vvi(2));
    for (auto e : re) adj[e[0]][0].push_back(e[1]);
    for (auto e : be) adj[e[0]][1].push_back(e[1]);

    queue<pii> q;
    vvi dist(n, vi(2,inf));
    q.emplace(0,0); q.emplace(0,1);
    dist[0][0] = dist[0][1] = 0;

    while (q.size()) {
      auto [u,c] = q.front();
      q.pop();
      for (auto v : adj[u][c]) {
        if (dist[v][1-c] < inf) continue;
        dist[v][1-c] = dist[u][c] + 1;
        q.emplace(v,1-c);
      }
    }
      
    vi ans(n, inf);
    for (int i=0; i<n; i++) {
      ans[i] = min(dist[i][0], dist[i][1]);
      if (ans[i] == inf) ans[i] = -1;
    }
    return ans;   
  }
};