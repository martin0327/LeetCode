using ll = long long;
class Solution {
public:
    int integerReplacement(int n) {
        map<ll,ll> vis;
        queue<ll> q;
        q.push(n);
        vis[n] = 0;
        while (q.size()) {
            ll u = q.front();
            q.pop();
            if (u == 1) return vis[u];
            if (u&1) {
                for (ll v : {u-1,u+1}) {
                    if (vis.count(v)) continue;
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
            else {
                ll v = u / 2;
                if (!vis.count(v)) {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};