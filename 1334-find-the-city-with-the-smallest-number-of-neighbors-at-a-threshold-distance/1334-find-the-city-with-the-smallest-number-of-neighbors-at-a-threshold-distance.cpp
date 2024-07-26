const int inf = 1e9;
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int tg) {
        vvi dist(n, vi(n,inf));
        for (int i=0; i<n; i++) dist[i][i] = 0;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int k=0; k<n; k++) {
            for (int u=0; u<n; u++) {
                for (int v=0; v<n; v++) {
                    if (dist[u][v] > dist[u][k] + dist[k][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                    }
                }
            }
        }
        int ans = -1, mn = inf;
        for (int i=0; i<n; i++) {
            int cnt = 0;
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                if (dist[i][j] <= tg) cnt++;
            }
            if (cnt <= mn) {
                ans = i;
                mn = cnt;
            }
        }
        return ans;
    }
};