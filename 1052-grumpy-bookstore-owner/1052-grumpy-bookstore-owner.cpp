class Solution {
public:
    int maxSatisfied(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<int> c(n), pre(n+1);
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (b[i]) c[i] = a[i];
            else ans += a[i];
        }
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + c[i-1];
        }
        int mx = 0;
        for (int i=k; i<=n; i++) {
            mx = max(mx, pre[i]-pre[i-k]);
        }
        ans += mx;
        return ans;        
    }
};