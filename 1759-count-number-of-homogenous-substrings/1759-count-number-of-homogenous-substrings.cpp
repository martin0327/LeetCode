using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int countHomogenous(string s) {
        ll p = 0, cnt = 0, ans = 0;
        for (ll x : s) {
            cnt = (p==x) ? cnt+1 : 1;
            ans += cnt;
            ans %= mod;
            p = x;
        }
        return ans;
    }
};