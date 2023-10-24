class Solution {
public:
    int minimumSum(vector<int>& a) {
        int n = a.size();
        int ans = 1e9;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (a[i] < a[j] && a[k] < a[j]) {
                        ans = min(ans, a[i]+a[j]+a[k]);
                    }
                }
            }
        }
        if (ans == 1e9) return -1;
        return ans;
    }
};