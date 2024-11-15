using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        ll n = a.size();
        vi pre(n,1), suf(n,1);
        for (int i=1; i<n; i++) {
            if (a[i] < a[i-1] || pre[i-1] == 0) pre[i] = 0;
        }
        for (int i=n-2; i>=0; i--) {
            if (a[i] > a[i+1] || suf[i+1] == 0) suf[i] = 0;
        }

        ll lo = 0, hi = n, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            bool ok = false;
            for (int i=0; i+mid-1<n; i++) {
                bool lb = (i == 0 || pre[i-1]);
                bool rb = (i+mid == n || suf[i+mid]);
                bool inc = ((i==0) || (i+mid==n) || (a[i-1] <= a[i+mid]));
                ok |= (lb && rb && inc);
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