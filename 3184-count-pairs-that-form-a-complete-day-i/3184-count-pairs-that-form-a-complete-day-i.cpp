class Solution {
public:
    int countCompleteDayPairs(vector<int>& a) {
        int ans = 0;
        map<int,int> mp;
        int mod = 24;
        for (auto x : a) {
            x %= mod;
            ans += mp[(mod-x)%mod];
            mp[x]++;
        }
        return ans;
    }
};