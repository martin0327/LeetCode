using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vi dp(high+1);
        dp[0] = 1;
        for (int i=0; i<high; i++) {
            if (i+zero <= high) {
                dp[i+zero] += dp[i];
                dp[i+zero] %= mod;
            }
            if (i+one <= high) {
                dp[i+one] += dp[i];
                dp[i+one] %= mod;
            }
        }
        ll ans = 0;
        for (int i=low; i<=high; i++) {
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};