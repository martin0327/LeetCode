class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> b(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                b[i][j] = a[j][i];
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i]==b[j]) ans++;
            }
        }
        return ans;
    }
};