using vi = vector<int>;

const int inf = 2e9;
class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int n = a.size();
        vi dp(n, -inf);
        function<int(int)> f = [&] (int i) {
            if (i >= n) return 0;
            if (dp[i] != -inf) return dp[i];
            return dp[i] = f(i+k) + a[i];
        };
        int ans = -inf;
        for (int i=0; i<n; i++) ans = max(ans, f(i));
        return ans;
    }
};
