using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<int,int,int>;
template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    k++;
    vvp adj(n);
    for (auto v : flights) {
      adj[v[0]].push_back({v[1],v[2]});
    }

    vvi dist(n, vi(k+1, inf));
    min_pq<ti3> pq;
    dist[src][0] = 0;
    pq.emplace(0,src,0);

    while (pq.size()) {
      auto [d,u,j] = pq.top();
      pq.pop();
      if (d > dist[u][j]) continue;
      if (j == k) continue;
      
      for (auto [v,w] : adj[u]) {
        if (d+w < dist[v][j+1]) pq.emplace(dist[v][j+1] = d+w, v, j+1);
      }
    }
    int ans = inf;
    for (int i=0; i<=k; i++) ans = min(ans, dist[dst][i]);
    if (ans == inf) ans = -1;
    return ans;
  }
};