class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int mx = 0;
        for (auto x : a) mx |= x;
        int n = a.size();
        int ans = 0;
        for (int mask=1; mask<(1<<n); mask++) {
            int x = 0;
            for (int i=0; i<n; i++) {
                if (mask>>i&1) x |= a[i];
            }
            if (x == mx) ans++;
        }
        return ans;
    }
};