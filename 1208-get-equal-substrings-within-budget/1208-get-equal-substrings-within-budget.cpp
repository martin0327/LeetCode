class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            a[i] = abs(s[i]-t[i]);
        }
        int lo = 1, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int s = 0;
            for (int i=0; i<mid; i++) {
                s += a[i];
            }
            bool ok = s <= maxCost;
            for (int i=mid; i<n; i++) {
                s += a[i];
                s -= a[i-mid];
                ok |= (s <= maxCost);
            }
            if (ok) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};