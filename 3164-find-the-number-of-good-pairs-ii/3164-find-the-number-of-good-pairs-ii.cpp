using ll = long long;
const int sz = 1e6;
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int k) {
        vector<ll> cnt(sz+1);        
        for (auto x : a) {
            for (int d=1; d*d <= x; d++) {
                if (x % d == 0) {
                    int y = d, z = x / d;
                    cnt[y]++;
                    if (y!=z) cnt[z]++;
                }
            }
        }
        ll ans = 0;
        for (auto y : b) {
            if (k*y <= sz) ans += cnt[k*y];
        }
        return ans;        
    }
};