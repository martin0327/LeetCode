using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
ll safe_mod(ll x) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
void add(ll &x, ll y) {
    x = safe_mod(x+y);
}
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = " " + s;
        vi dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            if (s[i] != '0') {
                if (s[i] == '*') add(dp[i], dp[i-1]*9);
                else add(dp[i], dp[i-1]);
            }
            if (i > 1) {
                if (s[i] == '*' && s[i-1] == '*') {
                    add(dp[i], dp[i-2]*15);
                }
                else if (s[i-1] == '*') {
                    int x = s[i] - '0';
                    if (x <= 6) add(dp[i], dp[i-2]*2);
                    else add(dp[i], dp[i-2]);
                }
                else if (s[i] == '*') {
                    int x = s[i-1] - '0';
                    if (x == 1) add(dp[i], dp[i-2]*9);
                    if (x == 2) add(dp[i], dp[i-2]*6);
                }
                else {
                    if (s[i-1] != '0') {
                        int x = stoi(s.substr(i-1,2));
                        if (10 <= x && x <= 26) {
                            add(dp[i],dp[i-2]);
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};