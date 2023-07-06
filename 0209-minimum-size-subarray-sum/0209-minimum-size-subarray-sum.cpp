using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        ll n = a.size();
        vi pre(n+1);
        for (int i=0; i<n; i++) pre[i+1] = pre[i] + a[i];
        ll lo = 0, hi = n, ans = 0;
        while (lo <= hi) {
            ll mid = (lo+hi) / 2;
            bool ok = false;
            for (int i=0; i+mid<=n; i++) {
                if (pre[i+mid]-pre[i] >= t) ok = true;
            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};