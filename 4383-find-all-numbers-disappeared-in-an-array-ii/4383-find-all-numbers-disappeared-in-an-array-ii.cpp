class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& a, int lo, int hi) {
        vector<bool> b(hi+1);
        for (auto x : a) {
            if (x <= hi) b[x] = 1; 
        }
        vector<vector<int>> ans;
        for (int i=lo; i<=hi; i++) {
            if (b[i]) continue;
            if (ans.empty()) ans.push_back({i,i});
            else {
                if (ans.back()[1] == i-1) ans.back()[1] = i;
                else ans.push_back({i,i});
            }
        }
        return ans;
    }
};