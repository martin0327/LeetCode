class Solution {
public:
    int incremovableSubarrayCount(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                vector<int> b;
                for (int k=0; k<n; k++) {
                    if (i <= k && k <= j) continue;
                    b.push_back(a[k]);
                }
                int m = b.size();
                bool ok = true;
                for (int i=1; i<m; i++) {
                    if (b[i] <= b[i-1]) ok = false;
                }
                ans += ok;
            }
        }
        return ans;
    }
};