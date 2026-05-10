using ll = long long;
class Solution {
public:
    int maximumJumps(vector<int>& a, int tg) {
        ll n = a.size();
        vector<ll> dp(n,-1);
        dp[0] = 0;
        for (int i=0; i+1<n; i++) {
            ll x = a[i];
            if (dp[i] == -1) continue;
            for (int j=i+1; j<n; j++) {
                ll y = a[j];
                if (x-tg <= y && y <= x+tg) {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }
        return dp.back();
    }
};