using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7, sz = 26;
ll dp[sz];
class Solution {
public:
    int distinctSubseqII(string s) {
        fill(dp,dp+sz,1);
        ll ans = 0;
        for (auto &ch : s) {
            ll x = ch - 'a';
            ans += dp[x];
            ans %= mod;
            for (int y=0; y<sz; y++) {
                if (y == x) continue;
                dp[y] += dp[x];
                dp[y] %= mod;
            }
        }
        return ans;
    }
};