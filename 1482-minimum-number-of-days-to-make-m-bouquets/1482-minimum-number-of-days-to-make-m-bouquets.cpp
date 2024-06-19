using ll = long long;
class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        ll n = a.size();
        ll lo = 1, hi = 1e9, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            vector<ll> b(n);
            for (int i=0; i<n; i++) {
                b[i] = (a[i] <= mid);
            }
            ll cnt = 0, cur = 0;
            for (int i=0; i<n; i++) {
                if (b[i]) cur++;
                else cur = 0;
                if (cur == k) {
                    cur = 0;
                    cnt++;
                }
            }
            if (cnt >= m) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};