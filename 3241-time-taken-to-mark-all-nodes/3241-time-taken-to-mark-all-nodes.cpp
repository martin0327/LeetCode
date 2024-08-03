using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        ll n = edges.size() + 1;
        vvi adj(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi base(n), sub(n), inv(n,-1);
        
        function<void(int,int)> f = [&] (int u, int p) {
            if (p != -1) {
                if (u&1) base[u] = base[p] + 1;
                else base[u] = base[p] + 2;
            }
            sub[u] = base[u];
            int sz = adj[u].size();
            for (int j=0; j<sz; j++) {
                int v = adj[u][j];
                if (v == p) continue;

                inv[v] = j;
                f(v,u);
                sub[u] = max(sub[u], sub[v]);
            }
        };
        f(0,-1);
        
        vector<int> ret(n);
        vvi b(n), pre(n), suf(n);
        function<void(int,int,int)> g = [&] (int u, int p, int cum) {
            int sz = adj[u].size();
            b[u] = pre[u] = suf[u] = vi(sz);
            for (int j=0; j<sz; j++) {
                int v = adj[u][j];
                if (v == p && p != -1) {
                    ll t = 0;
                    int idx = inv[u];
                    int sz2 = adj[p].size();
                    if (idx > 0) t = max(t, pre[p][idx-1]);
                    if (idx+1 < sz2) t = max(t, suf[p][idx+1]); 
                    b[u][j] = t + ((p&1)?1:2);
                }
                else {
                    b[u][j] = sub[v] - cum;
                }
            }
            for (int j=0; j<sz; j++) {
                if (j > 0) pre[u][j] = max(pre[u][j-1], b[u][j]);
                else pre[u][j] = b[u][j];
            }
            for (int j=sz-1; j>=0; j--) {
                if (j+1 < sz) suf[u][j] = max(suf[u][j+1], b[u][j]);
                else suf[u][j] = b[u][j];
            }
            for (auto v : adj[u]) {
                if (v == p) continue;
                g(v,u,cum + ((v&1)?1:2));
            }
        };
        g(0,-1,0);
        for (int i=0; i<n; i++) {
            ret[i] = *max_element(b[i].begin(), b[i].end());
        }

        return ret;
    }
};