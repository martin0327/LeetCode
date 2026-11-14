const int inf = 2e9;
class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int n = a.size(), ans = inf;
        for (int i=0; i<n; i++) {
            int s = 0;
            for (int j=i; j<n; j++) {
                s += a[j];
                int sz = j-i+1;
                if (l <= sz && sz <= r) {
                    if (s > 0) ans = min(ans, s);
                }
            }
        }
        if (ans == inf) ans = -1;
        return ans;
    }
};