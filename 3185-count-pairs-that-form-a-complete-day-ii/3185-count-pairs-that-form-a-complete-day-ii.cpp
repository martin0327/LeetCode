using ll = long long;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        ll ans = 0, mod = 24;
        map<ll,ll> mp;
        for (ll x : a) {
            x %= mod;
            x += mod;
            x %= mod;
            ll y = (mod-x) % mod;
            assert(0 <= x && x < mod);
            assert(0 <= y && y < mod);
            ans += mp[y];
            mp[x]++;
        }
        return ans;
    }
};