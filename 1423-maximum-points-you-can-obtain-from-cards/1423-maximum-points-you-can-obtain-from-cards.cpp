class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        using vi = vector<int>;
        vi pre(n+1), suf(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i-1];
            suf[i] = suf[i-1] + a[n-i];
        }
        int ans = 0;
        for (int i=0; i<=k; i++) {
            ans = max(ans, pre[i] + suf[k-i]);
        }
        return ans;
    }
};