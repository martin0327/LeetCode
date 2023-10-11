using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& a, int k) {

        vvi adj(n);
        for (auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        ll ans = 0;
        function<ll(ll,ll)> f = [&] (ll u, ll p) {
            ll ret = a[u];
            for (auto v : adj[u]) {
                if (v==p) continue;
                ret += f(v,u);
            }
            if (ret%k==0) ans++;
            return ret;
        };
        f(0,-1);
        return ans;

    }
};