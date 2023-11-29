class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        map<string,vector<int>> mp;
        for (auto b : a) {
            auto s = b[1];
            int x = stoi(s.substr(0,2)) * 60 + stoi(s.substr(2,2));
            mp[b[0]].push_back(x);
        }
        vector<string> ans;
        for (auto [k,v] : mp) {
            sort(v.begin(), v.end());
            int m = v.size();
            bool ok = false;
            for (int i=0; i+2<m; i++) {
                if (v[i+2] - v[i] < 60) ok = true;
            }
            if (ok) ans.push_back(k);
        }
        return ans;
    }
};