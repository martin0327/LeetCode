const int inf = 1e9;
class Solution {
public:
    int minimumSum(vector<int>& a) {
        int n = a.size();
        vector<int> suf(n+1,inf);
        for (int i=n-1; i>=0; i--) suf[i] = min(suf[i+1], a[i]);
        int ans = inf, x = inf;
        for (int i=1; i<n-1; i++) {
            x = min(x, a[i-1]);
            int y = suf[i+1];
            if (x < a[i] && y < a[i]) {
                ans = min(ans, x+y+a[i]);
            }            
        }
        if (ans == inf) return -1;
        return ans;
    }
};