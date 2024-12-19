using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size(), ans = 0;
        auto sa = a;
        sort(sa.begin(), sa.end());
        
        for (int mask=0; mask<(1<<(n-1)); mask++) {
            int sz = __builtin_popcount(mask);
            vvi b = {{a[0]}};
            for (int i=0; i<n-1; i++) {
                if (mask>>i&1) b.push_back({a[i+1]});
                else b.back().push_back(a[i+1]);
            }
            vi c;
            for (auto &v : b) {
                sort(v.begin(), v.end());
                for (auto &x : v) c.push_back(x);
            }
            if (c == sa) {
                ans = max(ans, sz+1);
            }
        }
        return ans;
    }
};