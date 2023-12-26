using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& a) {
        ll n = a.size();

        ll left = 1;
        for (int i=1; i<n; i++) {
            if (a[i] > a[i-1]) left++;
            else break;
        }
        if (left == n) return n*(n+1)/2;

        ll right = 1;
        for (int i=n-2; i>=0; i--) {
            if (a[i] < a[i+1]) right++;
            else break;
        }

        ll ans = left + right + 1;
        map<ll,ll> mp;
        for (int i=n-1; i>=0; i--) {
            if (i==n-1 || a[i] < a[i+1]) mp[a[i]] = i;
            else break;
        }
        for (int i=0; i<n; i++) {
            if (i == 0 || a[i] > a[i-1]) {
                auto it = mp.upper_bound(a[i]);
                if (it != mp.end()) {
                    int j = it->second;
                    ans += n - j;
                }
            }
            else break;
        }
        return ans;
    }
};