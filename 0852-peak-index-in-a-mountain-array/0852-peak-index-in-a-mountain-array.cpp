class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int lo = 1, hi = n-2, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (a[mid-1]<a[mid]) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};