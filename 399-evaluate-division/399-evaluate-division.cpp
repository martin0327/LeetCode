class Solution {
public:
    
    map<string,vector<pair<string,double>>> adj;
    set<string> check;
    
    double f(string s, string t) {
        if (s==t) return 1;
        check.insert(s);
        double ret = -1;
        for (auto [v,w] : adj[s]) {
            if (check.count(v)) continue;
            double temp = f(v,t);
            if (temp != -1) ret = w * temp;
        }
        return ret;
    }
    
    vector<double> calcEquation(vector<vector<string>>& a, vector<double>& b, vector<vector<string>>& queries) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            string u = a[i][0];
            string v = a[i][1];
            double w = b[i];
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,1/w);
        }
        
        vector<double> ans;
        for (auto q : queries) {
            string u = q[0];
            string v = q[1];
            if (!adj.count(u) || !adj.count(v)) {
                ans.push_back(-1.0);
                continue;
            }
            check.clear();
            ans.push_back(f(u,v));
        }
        return ans;
    }
};