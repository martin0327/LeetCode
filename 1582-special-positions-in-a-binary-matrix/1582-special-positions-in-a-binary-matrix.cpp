class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        auto f = [&] (int r) {
            int ret = 0;
            for (int i=0; i<m; i++) ret += a[r][i];
            return ret;
        };
        auto g = [&] (int c) {
            int ret = 0;
            for (int i=0; i<n; i++) ret += a[i][c];
            return ret;
        };
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] && f(i)==1 && g(j)==1) ans++;
            }
        }
        return ans;
        
    }
};