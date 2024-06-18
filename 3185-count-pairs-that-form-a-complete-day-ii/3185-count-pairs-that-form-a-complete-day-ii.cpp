using ll = long long;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        ll ans = 0, mod = 24;
        map<ll,ll> mp;
        for (ll x : a) {
            x %= mod;
            mp[x]++;
        }
        for (auto [x,cnt] : mp) {
            if (x==0 || x==12) continue;
            ans += cnt * mp[(mod-x)%mod];
        }
        ans /= 2;
        ans += mp[0]*(mp[0]-1)/2;
        ans += mp[12]*(mp[12]-1)/2;
        return ans;
    }
};
