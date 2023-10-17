using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 12345;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int k = n*m;
        
        vi pre(k+2,1), suf(k+2,1);
        for (int i=1; i<=k; i++) {
            int r = (i-1) / m, c = (i-1) % m;
            pre[i] = pre[i-1] * a[r][c];
            pre[i] %= mod;
        }
        for (int i=k; i>=1; i--) {
            int r = (i-1) / m, c = (i-1) % m;
            suf[i] = suf[i+1] * a[r][c];
            suf[i] %= mod;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int l = i * m + j + 1;
                a[i][j] = pre[l-1] * suf[l+1];
                a[i][j] %= mod;
            }
        }
        return a;
    }
};