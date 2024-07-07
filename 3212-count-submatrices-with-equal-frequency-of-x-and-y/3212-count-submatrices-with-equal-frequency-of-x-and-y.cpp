using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vvi b(n+1, vi(m+1));
        vvi c = b;
        vvi pre1 = b;
        vvi pre2 = c;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 'X') b[i+1][j+1] = 1;
                if (a[i][j] == 'Y') c[i+1][j+1] = 1;
            }
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                pre1[i][j] = pre1[i][j-1] + b[i][j];
                pre2[i][j] = pre2[i][j-1] + c[i][j];
            }
        }
        for (int j=1; j<=m; j++) {
            for (int i=1; i<=n; i++) {
                pre1[i][j] += pre1[i-1][j];
                pre2[i][j] += pre2[i-1][j];
            }
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (pre1[i][j] == pre2[i][j]) {
                    if (pre1[i][j] > 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};