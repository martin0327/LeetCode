class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        for (int i=0; i<n; i++) {
            sort(a[i].rbegin(), a[i].rend());
        }
        int ans = 0;
        for (int j=0; j<m; j++) {
            int temp = 0;
            for (int i=0; i<n; i++) {
                temp = max(temp, a[i][j]);
            }
            ans += temp;
        }
        return ans;
    }
};