template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
class Solution {
public:
    long long minCost(int n, string col, vector<vector<int>>& edg) {
        vvi adj(n);
        for (auto &uv : edg) {
            int u = uv[0], v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi cost(n,1), B(n), dp(n);
        function<void(ll,ll)> f = [&] (ll u, ll p) {
            for (auto v : adj[u]) {
                if (v == p) continue;
                f(v,u);
                cost[u] += cost[v];
                B[u] += B[v];
            }
            if (col[u] == 'R') B[u] += cost[u];
        };
        f(0,-1);
        
        ll ans = B[0];
        function<void(ll,ll)> g = [&] (ll u, ll p) {
            if (col[u] == 'B') dp[u] = cost[u];
            for (auto v : adj[u]) {
                if (v == p) continue;
                g(v,u);
                dp[u] += min(dp[v], B[v]);
            }
            chmin(ans, dp[u] + (B[0] - B[u]));
        };
        g(0,-1);
        return ans;
    }
};