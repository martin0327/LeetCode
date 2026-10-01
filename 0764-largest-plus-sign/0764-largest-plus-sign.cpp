using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& b) {
        vvi a(n, vi(n,1));
        for (auto &v : b) {
            auto r = v[0], c = v[1];
            a[r][c] = 0;
        }
        auto ph = a, sh = a;
        auto pv = a, sv = a;
        for (int i=0; i<n; i++) {
            for (int j=1; j<n; j++) {
                if (a[i][j]) ph[i][j] = ph[i][j-1] + 1;
            }
            for (int j=n-2; j>=0; j--) {
                if (a[i][j]) sh[i][j] = sh[i][j+1] + 1;
            }
        }
        for (int j=0; j<n; j++) {
            for (int i=1; i<n; i++) {
                if (a[i][j]) pv[i][j] = pv[i-1][j] + 1;
            }
            for (int i=n-2; i>=0; i--) {
                if (a[i][j]) sv[i][j] = sv[i+1][j] + 1;
            }
        }
        vector<vvi> t = {ph,sh,pv,sv};
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int mn = n;
                for (int l=0; l<4; l++) {
                    mn = min(mn, t[l][i][j]);
                }
                ans = max(ans, mn);
            }
        }
        return ans;
    }
};