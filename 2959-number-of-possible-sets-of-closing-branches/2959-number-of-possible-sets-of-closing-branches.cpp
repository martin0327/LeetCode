using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vvi adj(n, vi(n,inf));
        for (int i=0;i <n; i++) adj[i][i] = 0;
        for (auto uvw : roads) {
            int u = uvw[0], v = uvw[1], w = uvw[2];
            adj[u][v] = min(adj[u][v], w);
            adj[v][u] = min(adj[v][u], w);
        }
        int ans = 0;
        for (int mask=0; mask<(1<<n); mask++) {
            vvi dist(n, vi(n, inf));
            for (int i=0; i<n; i++) {
                dist[i][i] = 0;
                for (int j=0; j<n; j++) {
                    if (i==j) continue;
                    if (mask>>i&1) {
                        if (mask>>j&1) {
                            dist[i][j] = adj[i][j];
                        }
                    }
                }
            }
            for (int k=0; k<n; k++) {
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
            int t = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (mask>>i&1) {
                        if (mask>>j&1) {
                            t = max(t, dist[i][j]);
                        }
                    }
                }
            }
            if (t <= maxDistance) ans++;
        }
        return ans;
        
    }
};