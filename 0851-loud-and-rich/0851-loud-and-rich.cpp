using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& a) {
        int n = a.size();
        vvi adj(n);
        for (auto &uv : richer) {
            int u = uv[0], v = uv[1];
            adj[v].push_back(u);
        }
        auto f = [&] (int src) {
            queue<int> q;
            q.push(src);
            int mn = a[src];
            vi vis(n);
            vis[src] = 1;
            while (q.size()) {
                auto u = q.front();
                mn = min(mn, a[u]);
                q.pop();
                for (auto v : adj[u]) {
                    if (vis[v]) continue;
                    q.push(v);
                    vis[v] = 1;
                }
            }
            for (int i=0; i<n; i++) {
                if (vis[i]) {
                    if (mn == a[i]) return i;
                }
            }
            return -1;
        };
        vi ans(n);
        for (int i=0; i<n; i++) {
            ans[i] = f(i);
        }
        return ans;
    }
};