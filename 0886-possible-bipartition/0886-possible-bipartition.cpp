using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vvi adj(n);
        for (auto uv : dis) {
            int u = --uv[0];
            int v = --uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vi check(n, -1);
        bool ans = true;
        for (int i=0; i<n; i++) {
            if (check[i] != -1) continue;
            check[i] = 0;
            q.push(i);
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (check[v] == -1) {
                        check[v] = check[u] ^ 1;
                        q.push(v);
                    }
                    else if (check[v] == check[u]) ans = false;
                }
            }
        }
        return ans;
    }
};  