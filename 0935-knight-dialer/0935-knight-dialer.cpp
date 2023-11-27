using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;
const vi dr = {1,1,2,2}, dc = {2,-2,1,-1};

class Solution {
public:

    vvi mat_mul(vvi &a, vvi &b) {
        int n = a.size();
        vvi ret(n, vi(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    ret[i][j] += a[i][k] * b[k][j];
                    ret[i][j] %= mod;
                }
            }
        }
        return ret;
    }
    
    vvi mat_exp(vvi a, int e) {
        int n = a.size();
        vvi ret(n, vi(n));
        for (int i=0; i<n; i++) ret[i][i] = 1;
        while (e) {
            if (e&1) ret = mat_mul(ret, a);
            e >>= 1;
            a = mat_mul(a,a);
        }
        return ret;
    }

    int knightDialer(int n) {
        int R = 4, C = 3, m = R*C-2;
        vvi a(m, vi(m));
        
        for (int r=0; r<R-1; r++) {
            for (int c=0; c<C; c++) {
                int u = r*C+c;
                for (int d=0; d<4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= R) continue;
                    if (nc < 0 || nc >= C) continue;
                    if (nr==3 && nc!=1) continue;
                    int v = nr*C+nc;
                    if (v>=m) v = m-1;
                    a[u][v] = a[v][u] = 1;
                }                
            }
        }
        
        a = mat_exp(a,n-1);
        ll ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                ans += a[i][j]; 
                ans %= mod;
            }
        }
        
        return ans;
    }
}; 