class Solution {
public:
    int sumOfSquares(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            if (n % (i+1) == 0) {
                ans += a[i]*a[i];
            }
        }
        return ans;
    }
};