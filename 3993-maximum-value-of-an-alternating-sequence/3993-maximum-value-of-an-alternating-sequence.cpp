using ll = long long;
class Solution {
public:
    long long maximumValue(ll n, ll s, ll m) {
        if (n == 1) return s;
        if (n%2 == 0) n++;
        n /= 2;
        ll ans = s + n*(m-1) + 1;
        return ans;
    }
};