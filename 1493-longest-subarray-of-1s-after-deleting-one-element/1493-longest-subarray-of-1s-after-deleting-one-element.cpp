class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(),0);
        vector<int> pre(n+1), suf(n+2);
        for (int i=1; i<=n; i++) {
            if (a[i]) pre[i] = pre[i-1] + 1;
        }
        for (int i=n; i>=1; i--) {
            if (a[i]) suf[i] = suf[i+1] + 1;
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            ans = max(ans, pre[i-1] + suf[i+1]);
        }
        return ans;
    }
};