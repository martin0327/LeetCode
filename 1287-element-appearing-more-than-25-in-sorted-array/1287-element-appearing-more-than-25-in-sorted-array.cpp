class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        int ans = -1, mx = 0;
        for (auto [k,v] : mp) {
            if (v > mx) {
                ans = k;
                mx = v;
            }
        }
        return ans;
    }
};