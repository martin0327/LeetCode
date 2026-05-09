using ll = long long;
map<ll,ll> vis;
vector<ll> nb; 

class Solution {
public:
    int integerReplacement(int n) {
        vis.clear();
        nb.reserve(2);
        queue<ll> q;
        
        vis[n] = 0;
        q.push(n);
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