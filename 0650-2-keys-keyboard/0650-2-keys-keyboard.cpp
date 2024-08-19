using pii = pair<int,int>;
using vp = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
class Solution {
public:
    int minSteps(int n) {
        vvi vis(n+1, vi(n+1, inf));
        queue<pair<int,int>> q;
        vis[1][0] = 0;
        q.push({1,0});
        while (q.size()) {
            auto [u,d] = q.front();
            q.pop();
            pii v1 = {u+d,d};
            pii v2 = {u,u};
            vp nb = {v1,v2};
            for (auto [v,nd] : nb) {
                if (max(v,nd) <= n && vis[v][nd] == inf) {
                    vis[v][nd] = vis[u][d] + 1;
                    q.push({v,nd});
                }
            }
        }
        int ans = inf;
        for (int i=0; i<=n; i++) ans = min(ans, vis[n][i]);
        return ans;
    }
};