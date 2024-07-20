using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        int n = rs.size(), m = cs.size();
        vvi a(n, vi(m));
        vi b(m);
        for (int i=0; i<n; i++) {
            int x = rs[i];
            for (int j=0; j<m; j++) {
                int d = min(x,cs[j]-b[j]);
                if (d > 0) {
                    x -= d;
                    b[j] += d;
                    a[i][j] = d;
                }
            }
        }
        return a;
    }
};