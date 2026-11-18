using pii = pair<int,int>;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        vector<pii> a;
        for (int i=0; i<n; i++) {
            if (a.empty() || s[a.back().first] != s[i] ) a.push_back({i,1});
            else a.back().second++;
        }
        vector<vector<int>> ans;
        for (auto [i,cnt] : a) {
            if (cnt >= 3) ans.push_back({i,i+cnt-1});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};