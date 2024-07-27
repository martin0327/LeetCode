class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
            using ll = long long;
        using vi = vector<ll>;
        using vvi = vector<vi>;

        ll n = 26;
        ll m = original.size();

        ll inf = 2e18;
        vvi adj(n, vi(n,inf));
        for (int i=0; i<n; i++) adj[i][i] = 0;
        for (int i=0; i<m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u][v] = min(adj[u][v], (ll) cost[i]);
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        ll ans = 0;
        for (int i=0; i<source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (adj[u][v] == inf) return -1;
            else ans += adj[u][v];
        }

        return ans;
    }
};