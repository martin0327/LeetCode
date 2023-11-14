using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& a) {
        ll n = a.size();
        vvi adj(n);
        for (auto uv : edges) {
            int u = uv[0], v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<pii(ll,ll)> f = [&] (ll u, ll p) {
            ll x = 0, y = 0;
            for (auto v : adj[u]) {
                if (v==p) continue;
                auto [z,w] = f(v,u);
                x += z, y += w;
            }
            return make_pair(x + a[u], max(x,(x==0)?0:a[u]+y));
        };
        auto [z,w] = f(0,-1);
        return max(z-a[0],w);
    }
};