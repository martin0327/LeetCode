using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& par, string s) {
        int n = par.size(), sz = 26;
        vvi adj(n), st(sz);
        for (int i=1; i<n; i++) {
            adj[par[i]].push_back(i);
        }
        vi anc(n,-1), sub(n,1);
        function<void(int)> f = [&] (int u) {
            auto x = s[u] - 'a';
            if (st[x].size()) {
                anc[u] = st[x].back();
            }
            st[x].push_back(u);
            for (auto v : adj[u]) {
                f(v);
                sub[u] += sub[v];
                if (anc[v] != -1) {
                    sub[u] -= sub[v];
                    sub[anc[v]] += sub[v];
                }
            }
            st[x].pop_back();
        };
        f(0);
        return sub;
    }
};