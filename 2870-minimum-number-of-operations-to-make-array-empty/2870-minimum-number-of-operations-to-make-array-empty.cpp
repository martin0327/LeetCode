class Solution {
public:
    int minOperations(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        int sz = 1e5, inf = 1e9;
        vector<int> dp(sz+1, inf);
        dp[2] = dp[3] = 1;
        for (int i=4; i<=sz; i++) {
            dp[i] = min(dp[i-2],dp[i-3])+1;
        }
        int ans = 0;
        for (auto [k,v] : mp) {
            if (v==1) return -1;
            ans += dp[v];
        }
        return ans;
    }
};