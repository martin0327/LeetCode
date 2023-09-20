using vi = vector<int>;
const int inf = 1e9;

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int n = a.size();
        vi pre(n+1), suf(n+2);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
        for (int i=n; i>=1; i--) suf[i] = suf[i+1] + a[i-1];
        
        int ans = inf;
        for (int i=n+1; i>=1; i--) {
            int t = k - suf[i];
            auto it = lower_bound(pre.begin(), pre.end(),t);
            if (it != pre.end() && *it == t) {
                int l = it - pre.begin();
                int r = n+1 - i;
                if (l+r <= n) ans = min(ans, l+r);
            }
        }
        return (ans==inf) ? -1 : ans;
    }
};