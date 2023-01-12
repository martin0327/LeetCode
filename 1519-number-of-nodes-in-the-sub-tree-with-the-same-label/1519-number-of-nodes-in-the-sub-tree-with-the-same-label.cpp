class Solution {
public:
    
    int n;
    vector<vector<int>> cnt;
    vector<vector<int>> adj;
    vector<int> l;
    
    int dfs(int u, int p, int c) {
        cnt[u][c] += (c==l[u]);
        for (auto v : adj[u]) {
            if (v == p) continue;
            cnt[u][c] += dfs(v, u, c);            
        }
        return cnt[u][c];
    }
    
    vector<int> countSubTrees(int N, vector<vector<int>>& edges, string labels) {
        n = N;
        vector<vector<int>> temp_cnt(n, vector<int>(26));  // all initialized with 0
        cnt = temp_cnt;
        adj.resize(n);
        for (auto uv : edges) {
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        l.resize(n);
        for (int i=0; i<n; i++) l[i] = labels[i] - 'a';
        
        for (int c=0; c<26; c++) {
            dfs(0,-1,c);
        }
        vector<int> ret(n);
        for (int i=0; i<n; i++) {
            ret[i] = cnt[i][l[i]];
        }
        
        
        return ret;
        
    }
};