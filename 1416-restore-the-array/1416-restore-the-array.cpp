using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vi dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            ll cur = 0;
            ll prod = 1;
            for (int j=0; j<10; j++) {
                if (i-j < 1) break;
                ll x = s[i-j-1]-'0';
                cur += prod*x;
                prod *= 10;
                if (cur <= k && x > 0) {
                    dp[i] += dp[i-j-1];
                    dp[i] %= mod;
                }
                else if (cur > k) break;
            }
        }
        return dp[n];
    }
};