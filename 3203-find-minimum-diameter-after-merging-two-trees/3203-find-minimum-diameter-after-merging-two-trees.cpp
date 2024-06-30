using vi = vector<int>;
using vvi = vector<vi>;

template<typename T> 
pair<T,int> max_idx(vector<T> &a) {
    int n = a.size();
    vector<pair<T,int>> b(n);
    for (int i=0; i<n; i++) {
        b[i] = {a[i], i};
    }
    return *max_element(b.begin(), b.end());
}

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
            auto [mx, root] = max_idx(dep);
            
            dep = vi(n);
            g(root,-1,0);

            int ret = *max_element(dep.begin(), dep.end());
            return ret;
        };
        int d1 = f(e1), d2 = f(e2);
        int ans = (d1+1)/2 + (d2+1)/2 + 1;
        ans = max({ans,d1,d2});
        return ans;

    }
};