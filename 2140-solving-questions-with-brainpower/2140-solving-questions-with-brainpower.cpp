using ll = long long;
using vi = vector<ll>;
void chmax(ll &x, ll y) {x = max(x,y);}

class Solution {
public:
    long long mostPoints(vector<vector<int>>& a) {
        int n = a.size();
        ll ans = 0;
        vi dp(n);
        for (int i=0; i<n; i++) {
            int x = a[i][0], y = a[i][1];
            if (i+y+1 < n) chmax(dp[i+y+1],dp[i]+x);
            if (i+1 < n) chmax(dp[i+1],dp[i]);
            chmax(ans,dp[i]+x);
        }
        return ans;        
    }
};