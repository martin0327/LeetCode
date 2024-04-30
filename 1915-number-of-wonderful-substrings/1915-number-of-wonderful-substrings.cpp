using ll = long long;
class Solution {
public:
    long long wonderfulSubstrings(string s) {
        ll ans = 0, p = 0;
        vector<ll> b = {0}, cnt(1<<10);
        for (int i=0; i<10; i++) {
            b.push_back(1ll<<i);
        }
        cnt[0] = 1;
        for (auto c : s) {
            p ^= (1ll<<(c-'a'));
            for (auto x : b) {
                ans += cnt[x^p];
            }
            cnt[p]++;
        }
        return ans;
    }
};