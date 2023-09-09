class Solution {
public:
    using vi = vector<int>;
    vi a;
    vi dp;
    
    int f(int x) {
        if (dp[x] != -1) return dp[x];
        int ret = 0;
        for (auto y : a) {
            if (y < x) ret += f(x-y);
            if (y==x) ret++;
        }
        return dp[x] = ret;
    }
    
    int combinationSum4(vector<int>& nums, int t) {
        a = nums;
        dp = vi(1001, -1);
        int ans = f(t);
        return ans;
    }
};