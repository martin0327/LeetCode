using ll = long long;

class Solution {
public:
    int longestSubarray(vector<int>& a, int lim) {
        ll n = a.size(), lo = 1, hi = n, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            multiset<ll> s;
            for (int i=0; i<mid; i++) {
                s.insert(a[i]);
            }
            ll diff = *s.rbegin() - *s.begin();
            for (int i=mid; i<n; i++) {
                s.insert(a[i]);
                s.erase(s.find(a[i-mid]));
                diff = min(diff, *s.rbegin() - *s.begin());
            }
            if (diff <= lim) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        assert(ans != -1);
        return ans;
    }
};