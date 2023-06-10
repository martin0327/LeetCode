using ll = long long;

class Solution {
public:
    int maxValue(int n, int idx, int mx) {
        ll lo = 1, hi = 1e9, ans = -1;
        auto f = [&](ll n, ll x) {
            if (n >= x) return x*(x+1)/2 + (n-x);
            else return x*(x+1)/2 - (x-n)*(x-n+1)/2;
        };
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll s = f(idx,mid-1) + f(n-idx,mid);            
            if (s <= mx) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};