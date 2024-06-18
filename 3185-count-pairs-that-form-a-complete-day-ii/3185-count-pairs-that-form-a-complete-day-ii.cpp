using ll = long long;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        ll ans = 0, mod = 24;
        map<ll,ll> mp;
        for (ll x : a) {
            x %= mod;
            ll y = (mod-x) % mod;
            ans += mp[y];
            mp[x]++;
        }
        return ans;
    }
};