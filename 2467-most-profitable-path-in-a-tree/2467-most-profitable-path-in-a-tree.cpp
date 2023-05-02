using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 1e18;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int tg, vector<int>& a) {
        int n = edges.size() + 1;
        vvi adj(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi d1(n,inf), d2(n,inf);
        auto bfs = [&](int src, vi &d) {
            d[src] = 0;
            queue<ll> q;
            q.push(src);
            while (q.size()) {
                ll u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    if (d[v] < inf) continue;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        };
        bfs(0,d1);
        bfs(tg,d2);
        
        ll dd = d1[tg], ans = -inf;
        queue<ll> q;
        q.push(0);
        vi cost(n,inf);
        cost[0] = a[0];
        while (q.size()) {
            ll u = q.front(); q.pop();
            ll cnt = 0;
            for (auto v : adj[u]) {
                if (cost[v] < inf) continue;
                cnt++;
                q.push(v);
                if (d1[v]+d2[v] > dd) {
                    cost[v] = cost[u] + a[v];
                }
                else {
                    if (d1[v]<d2[v]) cost[v] = cost[u] + a[v];
                    else if (d1[v]==d2[v]) cost[v] = cost[u] + a[v]/2;
                    else cost[v] = cost[u];
                }
            }
            if (cnt==0) ans = max(ans, cost[u]);
        }
        return ans;
    }
};