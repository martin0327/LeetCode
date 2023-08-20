using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& bi) {
        int sz = m;
        for (int i=0; i<n; i++) {
            if (group[i] == -1) {
                group[i] = sz++;
            }
        }
        vvi a(sz);
        vvi adj(sz);
        for (int i=0; i<n; i++) {
            int u = group[i];
            a[u].push_back(i);
            for (auto j : bi[i]) {
                int v = group[j];
                if (u!=v) adj[v].push_back(u);
            }
        }
        for (int i=0; i<sz; i++) {
            vi &a = adj[i];
            if (a.empty()) continue;
            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());
        }
        
        auto f = [&] (vvi &adj) {
            int n = adj.size();
            vi deg(n);
            for (int i=0; i<n; i++) {
                for (auto j : adj[i]) deg[j]++;
            }
            queue<int> q;
            vi ret;
            for (int i=0; i<n; i++) {
                if (deg[i]==0) q.push(i);
            }
            while (q.size()) {
                int u = q.front(); q.pop();
                ret.push_back(u);
                for (auto v : adj[u]) {
                    if (!--deg[v]) q.push(v);
                }
            }
            return ret;
        };
        vi ret;
        auto outer = f(adj);
        if (outer.size() < sz) return {};
        
        for (auto g : outer) {
            int sz = a[g].size();
            map<int,int> inv;
            for (int i=0; i<sz; i++) {
                int u = a[g][i];
                inv[u] = i;
            }
            vvi adj(sz);
            for (int i=0; i<sz; i++) {
                int u = a[g][i];
                for (auto v : bi[u]) {
                    if (inv.count(v)) {
                        int j = inv[v];
                        adj[j].push_back(i);
                    }
                }
            }
            for (int i=0; i<sz; i++) {
                vi &a = adj[i];
                sort(a.begin(), a.end());
                a.erase(unique(a.begin(), a.end()), a.end());
            }
            auto inner = f(adj);
            if (inner.size() < sz) return {};
            
            for (auto i : inner) ret.push_back(a[g][i]);
        }
        return ret;        
    }
};