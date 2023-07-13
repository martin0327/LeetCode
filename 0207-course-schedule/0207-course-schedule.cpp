using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vvi adj(n);
        vi deg(n);
        for (auto uv : pr) {
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            deg[v]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (deg[i]==0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (--deg[v]==0) q.push(v);
            }
        }
        bool ans = true;
        for (int i=0; i<n; i++) {
            if (deg[i]) ans = false;
        }
        return ans;
    }
};