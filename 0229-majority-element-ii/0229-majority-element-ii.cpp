class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<int> ret;
        for (auto [k,v] : mp) {
            if (v > n/3) ret.push_back(k);
        }
        return ret;
    }
};