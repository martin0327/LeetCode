class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            ans += min(a[k] - (i > k), a[i]);
        }
        return ans;
    }
};