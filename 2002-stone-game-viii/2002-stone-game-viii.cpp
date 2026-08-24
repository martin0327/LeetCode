using vi = vector<int>;
class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n = a.size();
        for (int i=1; i<n; i++) {
            a[i] += a[i-1];
        }
        vi dp1(n), dp2(n), suf1(n), suf2(n);
        dp1[n-1] = dp2[n-1] = 0;
        suf1[n-1] = a[n-1];
        suf2[n-1] = -a[n-1];
        for (int i=n-2; i>=0; i--) {
            // for (int j=i+1; j<=n; j++) {
            //     chmax(dp1[i], dp2[j] + pre[j]);
            //     chmin(dp2[i], dp1[j] - pre[j]);
            // }
            dp1[i] = suf1[i+1];
            dp2[i] = suf2[i+1];
            suf1[i] = max(suf1[i+1], dp2[i] + a[i]);
            suf2[i] = min(suf2[i+1], dp1[i] - a[i]);
        }
        return dp1[0];
    }
};