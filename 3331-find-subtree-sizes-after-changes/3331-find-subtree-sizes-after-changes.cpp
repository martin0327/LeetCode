string s;
using vi = vector<int>;
const int maxn = 1e5+1;
vi adj[maxn], st[26];
int anc[maxn], sub[maxn];
void f(int u) {
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
}
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& par, string ss) {
        s = ss;
        int n = par.size(), sz = 26;
        for (int i=0; i<n; i++) adj[i].clear();
        for (int i=0; i<sz; i++) st[i].clear();
        for (int i=1; i<n; i++) adj[par[i]].push_back(i);
        fill(anc,anc+n,-1);
        fill(sub,sub+n,1);
        f(0);
        vi ans(sub,sub+n);
        return ans;
    }
};