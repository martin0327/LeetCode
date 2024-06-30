using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        
        function<signed(vvi&)> f = [&](vvi &e) {
            int n = e.size() + 1;
            vvi adj(n);
            for (auto uv : e) {
                int u = uv[0], v = uv[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vi dep(n);
            function<void(int,int,int)> g = [&] (int u, int p, int d) {
                dep[u] = d;
                for (auto v :adj[u]) {
                    if (v==p) continue;
                    g(v,u,d+1);
                }
            };
            g(0,-1,0);
            
            int root = max_element(dep.begin(), dep.end()) - dep.begin();
            dep = vi(n);
            g(root,-1,0);

            int ret = *max_element(dep.begin(), dep.end());
            return ret;
        };
        int d1 = f(e1), d2 = f(e2);
        int d3 = (d1+1)/2 + (d2+1)/2 + 1;
        return max({d1,d2,d3});
    }
};