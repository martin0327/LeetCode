class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        int mx = 0;
        for (auto [k,v] : mp) mx = max(mx, v);
        int ans = 0;
        for (auto [k,v] : mp) {
            if (v==mx) ans += v;
        }
        return ans;
    }
};