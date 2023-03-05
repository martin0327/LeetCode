class Solution {
public:
    long long countSubarrays(vector<int>& a, int lo, int hi) {
        if (lo > hi) return 0;
        int n = a.size();
        int mn = -1, mx = -1, blk = -1;
        long long ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] < lo || a[i] > hi) blk = i;
            if (a[i] == lo) mn = i;
            if (a[i] == hi) mx = i;
            int lim = min(mn,mx);
            if (lim > blk) ans += lim - blk;
        }
        return ans;
    }
};