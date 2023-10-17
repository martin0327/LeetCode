using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vi deg(n), vis(n);
        vvi adj(n);
        for (int u=0; u<n; u++) {
            {
                int v = l[u];
                if (v != -1) {
                    adj[u].push_back(v);
                    deg[v]++;
                }
            }
            {
                int v = r[u];
                if (v != -1) {
                    adj[u].push_back(v);
                    deg[v]++;
                }
            }
        }
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
            if (deg[i] > 1) return false;
        }
        if (q.size() != 1) return false;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (--deg[v] == 0) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        bool ret = true;
        for (auto x : vis) ret &= x;
        return ret;        
    }
};