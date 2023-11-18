using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        vi a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        ll n = a.size(), ans = 0;  
        a.insert(a.begin(), 0ll);
        vi pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
        for (int i=1; i<=n; i++) {
            ll lo = 0, hi = i, j = -1;
            while (lo <= hi) {
                ll m = (lo+hi)/2;
                ll s = pre[i] - pre[m];
                if (a[i]*(i-m) - s <= k) {
                    j = m;
                    hi = m - 1;
                }
                else lo = m + 1;
            }
            ans = max(ans, i-j);
        }
        return ans;
    }
};