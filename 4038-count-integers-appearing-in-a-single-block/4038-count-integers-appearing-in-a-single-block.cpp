class Solution {
public:
    int countSpecialIntegers(vector<int>& a) {
        vector<int> b;
        for (auto x : a) {
            if (b.empty() || b.back() != x) b.push_back(x);
        }
        map<int,int> mp;
        for (auto x : b) mp[x]++;
        int ans = 0;
        for (auto [k,v] : mp) {
            if (v == 1) ans++;
        }
        return ans;
    }
};