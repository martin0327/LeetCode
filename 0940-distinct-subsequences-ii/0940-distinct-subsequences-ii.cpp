using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        vi dp(26,1);
        ll ans = 0, sz = 26;
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