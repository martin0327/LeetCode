class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<int> ans;
        for (auto &[k,v] : mp) {
            if (v == 2) ans.push_back(k);
        }
        return ans;
    }
};