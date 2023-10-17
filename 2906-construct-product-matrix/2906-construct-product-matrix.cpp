using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 12345;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vvi pre(n+2, vi(m+2,1)), suf(n+2, vi(m+2,1));

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                pre[i][j] = pre[i][j-1] * a[i-1][j-1];
                pre[i][j] %= mod;
            }
            for (int j=m; j>=1; j--) {
                suf[i][j] = suf[i][j+1] * a[i-1][j-1]; 
                suf[i][j] %= mod;
            }
        }
        vi pre2(n+2,1), suf2(n+2,1);
        for (int i=1; i<=n; i++) {
            pre2[i] = pre2[i-1] * pre[i][m];
            pre2[i] %= mod;
        }
        for (int i=n; i>=1; i--) {
            suf2[i] = suf2[i+1] * pre[i][m];
            suf2[i] %= mod;
        }
        

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                ll x = pre2[i-1] * suf2[i+1];
                x %= mod;
                x *= pre[i][j-1] * suf[i][j+1];
                x %= mod;
                a[i-1][j-1] = x;
            }
        }
        return a;
    }
};