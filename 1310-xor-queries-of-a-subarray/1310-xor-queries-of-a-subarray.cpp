class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& qr) {
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] ^ a[i];
        }
        int q = qr.size();
        vector<int> ans(q);
        for (int i=0; i<q; i++) {
            int l = qr[i][0], r = qr[i][1];
            ans[i] = pre[r+1] ^ pre[l];
        }
        return ans;
    }
};