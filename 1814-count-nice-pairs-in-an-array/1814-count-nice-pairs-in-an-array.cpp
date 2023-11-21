using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int countNicePairs(vector<int>& a) {
        ll ans = 0;
        map<ll,ll> mp;
        for (auto x : a) {
            string s = to_string(x);
            reverse(s.begin(), s.end());
            ll y = x - stoll(s);
            ans += mp[y];
            ans %= mod;
            mp[y]++;
        }
        return ans;
    }
};