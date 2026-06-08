using ll = long long;
class Solution {
public:
    long long maxTotalValue(vector<int>& a, ll k) {
        auto mx = *max_element(a.begin(), a.end());
        auto mn = *min_element(a.begin(), a.end());
        ll ans = k * (mx - mn);
        return ans;
    }
};