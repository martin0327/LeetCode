using ll = long long;
const int sz = 1e6;
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int k) {
        vector<ll> cnt(sz+1);
        for (auto x : b) cnt[x]++;
        ll ans = 0;
        for (auto x : a) {
            for (int d=1; d*d <= x; d++) {
                if (x % d == 0) {
                    int y = d, z = x / d;
                    if (y % k == 0) ans += cnt[y/k];
                    if (z % k == 0 && z != y) ans += cnt[z/k];
                }
            }
        }
        return ans;        
    }
};