using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int countHomogenous(string s) {
        ll x = 1, n = s.size(), ans = 0;
        for (int i=1; i<n; i++) {
            if (s[i] == s[i-1]) x++;
            else {
                ans += x*(x+1)/2;
                ans %= mod;
                x = 1;
            }
        }
        ans += x*(x+1)/2;
        ans %= mod;
        return ans;
    }
};