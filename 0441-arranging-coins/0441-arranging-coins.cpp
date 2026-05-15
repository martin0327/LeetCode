using ll = long long;
class Solution {
public:
    int arrangeCoins(int n) {
        ll lo = 0, hi = n, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            if (mid*(mid+1)/2 <= n) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid -1;
        }
        return ans;
    }
};
