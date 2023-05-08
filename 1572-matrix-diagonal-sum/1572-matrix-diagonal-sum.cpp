class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int n = a.size();
        int ret = 0;
        for (int i=0; i<n; i++) {
            ret += a[i][i];
            ret += a[i][n-1-i];
        }
        if (n&1) ret -= a[n/2][n/2];
        return ret;
    }
};