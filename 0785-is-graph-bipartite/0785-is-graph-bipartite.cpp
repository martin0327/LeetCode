using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vi check(n, -1);
        
        bool res = true;
        function<void(int,int)> f = [&](int u, int c) {
            check[u] = c;
            for (auto v : adj[u]) {
                if (check[v]==-1) f(v,1^c);
                else if (check[v]==c) res = false;
            }
        };
        for (int i=0; i<n; i++) {
            if (check[i]==-1) f(i,0);
        }
        return res;        
    }
};