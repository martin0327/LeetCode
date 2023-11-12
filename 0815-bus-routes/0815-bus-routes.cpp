using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int sz = 1e6;
        vvi adj(sz);
        int m = routes.size();
        for (int i=0; i<m; i++) {
            for (auto u : routes[i]) {
                adj[u].push_back(i);
            }
        }
        queue<int> q;
        q.push(source);
        vi check(m);
        vi dist(sz, -1);
        dist[source] = 0;
        while (q.size()) {
            auto u = q.front(); 
            q.pop();
            for (auto rt : adj[u]) {
                if (check[rt]) continue;
                check[rt] = 1;
                for (auto v : routes[rt]) {
                    if (dist[v] != -1) continue;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[target];        
    }
};