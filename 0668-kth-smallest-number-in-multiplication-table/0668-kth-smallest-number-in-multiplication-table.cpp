class Solution {
public:
    int findKthNumber(int n, int m, int k) {
        int lo = 1, hi = n*m, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int cnt = 0;
            for (int i=1; i<=n; i++) {
                if (mid >= i*m) cnt += m;
                else cnt += mid / i;
            }
            if (cnt >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};