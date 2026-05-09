using ll = long long;
class Solution {
public:
    int integerReplacement(int n) {
        map<ll,ll> vis;
        queue<ll> q;
        q.push(n);
        vis[n] = 0;
        vector<ll> nb; nb.reserve(2);
        while (q.size()) {
            ll u = q.front(); q.pop();
            if (u == 1) return vis[u];
            nb = {u/2};
            if (u&1) nb = {u-1,u+1};
            
            for (auto v : nb) {
                if (vis.count(v)) continue;
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
        return -1;
    }
};