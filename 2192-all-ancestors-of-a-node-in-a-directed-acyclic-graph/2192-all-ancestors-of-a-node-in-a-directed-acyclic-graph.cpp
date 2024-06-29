using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vvi adj(n);
        vi indeg(n);
        for (auto uv : edges) {
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        vector<set<int>> ans(n);
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indeg[i]==0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                indeg[v]--;
                ans[v].insert(u);
                for (auto z : ans[u]) {
                    ans[v].insert(z);
                }
                if (indeg[v]==0) {
                    q.push(v);
                }
            }
        }
        vvi ans2(n);
        for (int i=0; i<n; i++) {
            for (auto x : ans[i]) {
                ans2[i].push_back(x);
            }
        }
        return ans2;
    }
};