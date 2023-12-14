using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vi r0(n),r1(n),c0(m),c1(m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) {
                    r1[i]++;
                    c1[j]++;
                }
                else {
                    r0[i]++;
                    c0[j]++;
                }
            }
        }
        vvi ret(n, vi(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ret[i][j] = r1[i]+c1[j]-r0[i]-c0[j];
            }
        }
        return ret;
    }
};