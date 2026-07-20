class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        auto b = a;
        k %= n*m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                auto x = i*m+j+k;
                x %= n*m;
                b[x/m][x%m] = a[i][j];
            }
        }
        return b;        
    }
};
