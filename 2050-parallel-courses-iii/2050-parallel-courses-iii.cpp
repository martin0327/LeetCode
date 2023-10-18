using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& a) {
        vvi adj(n);
        vi deg(n);
        for (auto uv : rel) {
            int u = uv[0] - 1, v = uv[1] - 1;
            adj[u].push_back(v);
            deg[v]++;
        }
        vi res(n);
        ll ans = 0;
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (deg[i]==0) {
                q.push(i);
                res[i] = a[i];
            }
        }

        while (q.size()) {
            int u = q.front(); q.pop();
            ans = max(ans, res[u]);
            for (auto v : adj[u]) {
                res[v] = max(res[v], res[u] + a[v]);
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};