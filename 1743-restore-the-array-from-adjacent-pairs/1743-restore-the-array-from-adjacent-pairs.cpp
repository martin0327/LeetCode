class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        map<int,int> mp;
        map<int,vector<int>> adj;
        for (auto uv : a) {
            int u = uv[0];
            int v = uv[1];
            mp[u]++;
            mp[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int u = -1;
        for (auto [k,v] : mp) {
            if (v==1) u = k;
        }
        vector<int> ret;
        while (true) {
            int p = ret.size() ? ret.back() : -1;
            ret.push_back(u);
            if (adj[u].size()==1) {
                if (ret.size()==1) u = adj[u].back();
                else break;
            }
            else {
                int v0 = adj[u][0];
                int v1 = adj[u][1];
                u = (p == v0) ? v1 : v0;
            }
        }
        return ret;
    }
};