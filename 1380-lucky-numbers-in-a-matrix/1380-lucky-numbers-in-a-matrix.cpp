class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> ans;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == *min_element(a[i].begin(), a[i].end())) {
                    int mx = a[i][j];
                    for (int l=0; l<n; l++) mx = max(mx, a[l][j]);
                    if (a[i][j] == mx) {
                        ans.push_back(mx);
                    }
                }
            }
        }
        return ans;
    }
};