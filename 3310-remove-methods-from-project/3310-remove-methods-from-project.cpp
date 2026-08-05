using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invk) {
        vvi adj(n), radj(n);
        for (auto &b : invk) {
            auto u = b[0], v = b[1];
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        auto f = [&] (vi src, vvi &adj) {
            vi vis(n);
            queue<int> q;
            for (auto v : src) {
                vis[v] = 1;
                q.push(v);
            }
            while (q.size()) {
                auto u = q.front();
                q.pop();
                for (auto &v : adj[u]) {
                    if (vis[v]) continue;
                    vis[v] = 1;
                    q.push(v);
                }
            }
            return vis;
        };

        vi src1 = {k}, src2;
        auto vis1 = f(src1, adj);
        for (int i=0; i<n; i++) {
            if (vis1[i]) src2.push_back(i);
        }
        auto vis2 = f(src2, radj);
        if (vis1 != vis2) {
            vi ans(n);
            for (int i=0; i<n; i++) ans[i] = i;
            return ans;
        }
        else {
            vi ans;
            for (int i=0; i<n; i++) {
                if (!vis1[i]) ans.push_back(i);
            }
            return ans;
        }
    }
};