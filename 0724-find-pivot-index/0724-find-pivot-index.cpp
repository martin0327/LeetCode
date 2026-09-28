class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + a[i];
        }
        for (int i=1; i<=n; i++) {
            auto x = pre[i-1];
            auto y = pre[n] - pre[i];
            if (x == y) return i-1;
        }
        return -1;
    }
};