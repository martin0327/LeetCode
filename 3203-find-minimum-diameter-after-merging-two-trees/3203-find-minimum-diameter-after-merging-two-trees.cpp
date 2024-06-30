using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {

        int n = e1.size() + 1;
        int m = e2.size() + 1;

        auto f = [&] (vector<vector<int>>& e) {
            int n = e.size() + 1;
            vvi adj(n);
            vi deg(n);
            for (auto v : e) {
                adj[v[0]].push_back(v[1]);
                adj[v[1]].push_back(v[0]);
                deg[v[0]]++;
                deg[v[1]]++;
            }
            queue<int> q;
            for (int i=0; i<n; i++) {
                if (deg[i] == 1) q.push(i);
            }
            int ret = -1;
            while (q.size()) {
                auto u = q.front();
                q.pop();
                ret = u;
                for (auto v : adj[u]) {
                    if (--deg[v] == 1) {
                        q.push(v);
                    }
                }
            }
            return ret;
        };
        auto c1 = (e1.empty()) ? 0 : f(e1);
        auto c2 = (e2.empty()) ? 0 : f(e2);

        for (auto uv : e2) {
            int u = uv[0], v = uv[1];
            u += n, v += n;
            e1.push_back({u,v});
        }
        e1.push_back({c1,c2+n});
        
        n += m;
        vvi adj(n);
        for (auto uv : e1) {
            int u = uv[0], v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi dep(n);
        function<void(int,int,int)> g = [&] (int u, int p, int d) {
            dep[u] = d;
            for (auto v : adj[u]) {
                if (v == p) continue;
                g(v,u,d+1);
            }
        };
        g(0,-1,0);
        int mx = 0, root = -1;
        for (int i=0; i<n; i++) {
            if (dep[i] > mx) {
                mx = dep[i];
                root = i;
            }
        }
        dep.assign(n,0);
        g(root,-1,0);
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max(ans, dep[i]);
        }
        return ans;
    }
};