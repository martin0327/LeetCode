class Solution {
public:
    long long countSubarrays(vector<int>& a, int lo, int hi) {
        if (lo > hi) return 0;
        int n = a.size();
        int mn = -1, mx = -1, l = -1;
        long long ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] < lo || a[i] > hi) l = i;
            if (a[i] == lo) mn = i;
            if (a[i] == hi) mx = i;
            int r = min(mn,mx);
            if (r > l) ans += r - l;
        }
        return ans;
    }
};