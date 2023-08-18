using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vvi adj(n, vi(n));
        vi deg(n);
        for (auto uv : roads) {
            int u = uv[0];
            int v = uv[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            deg[u]++;
            deg[v]++;
        }        
        ll ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                ll cnt = deg[i] + deg[j] - adj[i][j];
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};