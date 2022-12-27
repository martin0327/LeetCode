class Solution {
public:
    int maximumBags(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<int> c(n);
        for (int i=0; i<n; i++) {
            c[i] = a[i] - b[i];
        }
        sort(c.begin(), c.end());
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (k < c[i]) break;
            ans++;
            k -= c[i];
        }
        return ans;
    }
};