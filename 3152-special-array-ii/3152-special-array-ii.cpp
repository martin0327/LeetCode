class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& qr) {
        int n = a.size();
        vector<int> pre(n);
        for (int i=1; i<n; i++) {
            pre[i] = pre[i-1] + ((a[i]+a[i-1])%2==0);
        }
        int q = qr.size();
        vector<bool> ans(q);
        for (int i=0; i<q; i++) {
            int l = qr[i][0], r = qr[i][1];
            ans[i] = (pre[r] - pre[l] == 0);
        }
        return ans;
    }
};