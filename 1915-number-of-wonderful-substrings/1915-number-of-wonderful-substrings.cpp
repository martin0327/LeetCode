using ll = long long;
class Solution {
public:
    long long wonderfulSubstrings(string s) {
        ll ans = 0, p = 0;
        vector<ll> b = {0};
        for (int i=0; i<10; i++) {
            b.push_back(1ll<<i);
        }
        map<ll,ll> mp; mp[0]++;
        for (auto c : s) {
            p ^= (1ll<<(c-'a'));
            for (auto x : b) {
                ll t = x ^ p;
                auto it = mp.find(t);
                if (it != mp.end()) ans += it->second;
            }
            mp[p]++;
        }
        return ans;
    }
};