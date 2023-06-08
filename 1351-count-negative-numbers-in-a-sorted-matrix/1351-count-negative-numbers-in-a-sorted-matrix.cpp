class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0, j = m-1;
        for (int i=0; i<n; i++) {
            while (j >= 0 && a[i][j] < 0) j--;
            ans += (m-1-j);
        }
        return ans;
    }
};