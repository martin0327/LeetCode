using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int numOfMinutes(int n, int root, vector<int>& par, vector<int>& a) {
        vvi adj(n);
        for (int i=0; i<n; i++) {
            if (par[i] != -1) adj[par[i]].push_back(i);
        }
        ll ans = 0;
        function<void(ll,ll)> f = [&](ll u, ll c) {
            ans = max(ans, c);
            for (auto v : adj[u]) {
                f(v,c+a[u]);
            }
        };
        f(root,0ll);
        return ans;
    }
};