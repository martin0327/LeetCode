using ll = long long;
class Solution {
public:
    long long minimumReplacement(vector<int>& a) {
        ll n = a.size(), cur = a.back(), ans = 0;
        for (int i=n-2; i>=0; i--) {
            ll x = a[i];
            if (x > cur) {
                ll q = (x+cur-1)/cur;
                ans += q-1;
                cur = x / q;
            }
            else cur = x;            
        }
        return ans;
    }
};