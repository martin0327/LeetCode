using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vvi radj(n);
        vi loop(n);
        for (int u=0; u<n; u++) {
            for (auto v : adj[u]) {
                if (u==v) loop[u] = 1;
                else radj[v].push_back(u);
            }
        }
        vi vis(n), comp(n), st;
        function<void(int,int,int)> f = [&](int u, int flag, int idx) {
            vis[u] = 1;
            for (auto v : flag?adj[u]:radj[u]) {
                if (!vis[v]) f(v,flag,idx);
            }
            if (flag) st.push_back(u);
            else comp[u] = idx;
        };
        for (int i=0; i<n; i++) if (!vis[i]) f(i,1,0);
        vis.assign(n,0);
        int m = 0;
        reverse(st.begin(), st.end());
        for (auto u : st) if (!vis[u]) f(u,0,m++);
        vector<int> csz(m);
        for (int i=0; i<n; i++) csz[comp[i]]++;
        queue<int> q;
        vis.assign(n,0);
        for (int i=0; i<n; i++) {
            if (csz[comp[i]] > 1 || loop[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : radj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};