using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& a) {
        ll n = a.size(), ans = 0, mx = 0;
        vector<ll> suf(n+1);
        for (int i=n-1; i>=0; i--) suf[i] = max(suf[i+1],(ll)a[i]);
        for (int j=1; j<n-1; j++) {
            mx = max(mx, (ll)a[j-1]);
            ans = max(ans, (mx-a[j])*suf[j+1]);
        }
        return ans;
    }
};