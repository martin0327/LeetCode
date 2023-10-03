using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& a) {
        ll n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    ans = max(ans, (ll) (a[i]-a[j])*a[k]);
                }
            }
        }
        return ans;
    }
};