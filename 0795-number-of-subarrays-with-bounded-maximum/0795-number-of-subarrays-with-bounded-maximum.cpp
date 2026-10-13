class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int lo, int hi) {
        int n = a.size(), ans = 0;
        int l = -1, r = -1;
        for (int i=0; i<n; i++) {
            if (a[i] > hi) l = i;
            else if (a[i] >= lo) r = i;
            if (r > l) ans += r-l;
        }
        return ans;
    }
};