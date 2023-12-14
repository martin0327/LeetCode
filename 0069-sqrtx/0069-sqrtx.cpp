class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x, ans = -1;
        while (lo <= hi) {
            long long mid = (lo+hi) / 2;
            if (mid*mid <= x) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};