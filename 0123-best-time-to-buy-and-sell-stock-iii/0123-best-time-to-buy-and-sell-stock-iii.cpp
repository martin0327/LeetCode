using vi = vector<int>;
const int inf = 1e9;
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(),0);
        vi pre(n+1,-inf), suf(n+2,-inf);
        int cur = inf;
        for (int i=1; i<=n; i++) {
            pre[i] = max(pre[i-1], a[i] - cur);
            cur = min(cur, a[i]);
        }
        cur = -inf;
        for (int i=n; i>=1; i--) {
            suf[i] = max(suf[i+1], cur - a[i]);
            cur = max(cur, a[i]);
        }
        int ans = 0;
        for (int i=1; i<n; i++) ans = max(ans, pre[i]+suf[i+1]);
        return max({ans, pre[n],suf[1]});
    }
};