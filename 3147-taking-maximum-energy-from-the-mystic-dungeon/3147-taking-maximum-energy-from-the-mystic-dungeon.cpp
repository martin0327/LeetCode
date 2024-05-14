const int inf = 2e9;
class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n);
        int ans = -inf;
        for (int i=n-1; i>=0; i--) { 
            if (i+k >= n) dp[i] = a[i];
            else dp[i] = a[i] + dp[i+k];
            ans = max(ans, dp[i]);
        }
        return ans;        
    }
};