class Solution {
public:
    int islandPerimeter(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;
        vector<int> dr = {0,0,-1,1}, dc = {1,-1,0,0};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) {
                    for (int k=0; k<4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) ans++;
                        else if (!a[ni][nj]) ans++;
                    }
                }
            }
        }
        return ans;
    }
};