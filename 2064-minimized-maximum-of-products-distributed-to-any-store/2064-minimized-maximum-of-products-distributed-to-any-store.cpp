using ll = long long;
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& a) {
        ll lo = 1, hi = 1e5, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll cnt = 0;
            for (auto &x: a) {
                cnt += (x+mid-1)/mid;
            }
            if (cnt <= n) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};