class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        while (r-l >= 3) {
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            if (a[m1]  < a[m2]) l = m1;
            else r = m2;
        }
        int ans = -1, mx = -1;
        for (int i=l; i<=r; i++) {
            if (a[i] > mx) {
                mx = a[i];
                ans = i;
            }
        }
        return ans;
    }
};