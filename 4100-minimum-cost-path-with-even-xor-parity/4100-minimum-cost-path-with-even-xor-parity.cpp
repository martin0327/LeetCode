template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
const ll inf = 2e18;
class Solution {
public:
    int minActivationCost(vector<vector<int>>& edg, vector<int>& a) {
        int n = a.size();
        vvp adj(n);
        for (auto &e : edg) {
            auto u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vi wt(n);
        function<void(int,int)> f = [&] (int u, int p) {
            a[u] = __builtin_popcount(a[u])&1;
            for (auto [v,w] : adj[u]) {
                if (v == p) continue;
                wt[v] =  w;
                f(v,u);
            }
        };
        f(0,-1);
        ll ans = inf;
        function<vi(int,int)> g = [&] (int u, int p) {
            vi ret = {inf,inf}, cur = {inf,inf};
            ret[a[u]] = wt[u];
            for (auto [v,w] : adj[u]) {
                if (v == p) continue;
                auto t = g(v,u);
                chmin(ans, t[a[u]]);
                for (int i=0; i<2; i++) {
                    chmin(ret[i^a[u]], t[i]+wt[u]);
                    chmin(ans, cur[i^a[u]]+t[i]);
                    chmin(cur[i], t[i]);
                }
            }
            return ret;
        };
        g(0,-1);
        if (ans == inf) ans = -1;
        return ans;
    }
};