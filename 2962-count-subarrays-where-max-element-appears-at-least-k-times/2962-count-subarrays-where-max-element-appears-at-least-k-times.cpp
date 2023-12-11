using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        ll n = a.size(), mx = *max_element(a.begin(), a.end());
        vi b = {-1};
        for (int i=0; i<n; i++) {
            if (a[i] == mx) b.push_back(i);
        }
        ll m = b.size(), ans = 0;
        for (int i=1; i+k-1<m; i++) {
            ans += (b[i]-b[i-1])*(n-b[i+k-1]);
        }
        return ans;
    }
};