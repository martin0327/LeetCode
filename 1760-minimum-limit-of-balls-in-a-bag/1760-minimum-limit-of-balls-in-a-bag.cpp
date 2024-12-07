using ll = long long;

class Solution {
public:
    int minimumSize(vector<int>& a, int mx) {
        ll lo = 1, hi = 1e9, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll cnt = 0;
            for (ll x : a) {
                cnt += (x+mid-1) / mid - 1;
            }
            if (cnt <= mx) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};