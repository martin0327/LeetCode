using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vvi adj(n);
        for (auto uv : edges) {
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = inf;
        for (int i=0; i<n; i++) {
            queue<int> q;
            q.push(i);
            vi dist(n, -1);
            dist[i] = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (dist[v] != -1) {
                        if (dist[v] < dist[u]) continue;
                        ans = min(ans, dist[u]+dist[v]+1);
                    }
                    else {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        if (ans==inf) ans = -1;
        return ans;
    }
};