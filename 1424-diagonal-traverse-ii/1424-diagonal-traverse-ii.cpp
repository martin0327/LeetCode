class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        int n = a.size();
        map<pair<int,int>, int> mp;
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int m = a[i].size();
            for (int j=0; j<m; j++) {
                mp[{i+j,j}] = a[i][j];
            }
        }
        for (auto [k,v] : mp) ans.push_back(v);
        return ans;
    }
};