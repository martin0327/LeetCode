class Solution {
public:
    int minimumCost(vector<int>& a) {
        int n = a.size();
        int ans = 1e9;
        for (int j=1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                int x = a[0] + a[j] + a[k];
                ans = min(ans, x);
            }
        }
        return ans;
    }
};