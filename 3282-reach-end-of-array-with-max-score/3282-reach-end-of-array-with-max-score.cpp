using ll = long long;
class Solution {
public:
    long long findMaximumScore(vector<int>& a) {
        ll cur = 0, ans = 0;
        for (ll x : a) {
            cur = max(cur, x);
            ans += cur;
        }
        return ans - cur;
    }
};