using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n = a.size();
        vi pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
        ll ans = -1, mn = 1e18;
        for (int i=1; i<=n; i++) {
            ll x = pre[i] / i;
            ll y = (i<n) ? (pre[n]-pre[i]) / (n-i) : 0;
            if (mn > abs(x-y)) {
                mn = abs(x-y);
                ans = i-1;
            }
        }
        return ans;
    }
}; 