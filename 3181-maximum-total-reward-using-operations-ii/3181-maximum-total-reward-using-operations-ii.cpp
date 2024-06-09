using vi = vector<int>;
const int sz = 50001;
using bt = bitset<sz>;

class Solution {
public:
    int maxTotalReward(vector<int>& a) {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        
        bt dp;
        dp.set(0);
        for (auto x : a) {
            bt y;
            y.set();
            y >>= (sz-x);
            y &= dp;
            dp |= (y<<x);
        }
        
        int ans = 0, last = 0;
        vi b(sz);
        for(auto x : a) b[x] = 1;
        for (int i=1; i<sz; i++) {
            if (b[i]) {
                ans = max(ans, i + last);
            }
            if (dp[i]) {
                last = i;
                ans = max(ans, i);
            }
        }
        
        return ans;
    }
};