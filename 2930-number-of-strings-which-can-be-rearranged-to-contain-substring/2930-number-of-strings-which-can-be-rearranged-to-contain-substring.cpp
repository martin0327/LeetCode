using ll = long long;
using ti3 = tuple<ll,ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

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

    int stringCount(int n) {
        map<ti3,int> mp;
        ll m = 0;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<3; k++) {
                    mp[{i,j,k}] = m++;
                }
            }
        }
        
        vvi a(m, vi(m));
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<3; k++) {
                    int ni = min(1,i+1);
                    int nj = min(1,j+1);
                    int nk = min(2,k+1);
                    ll u = mp[{i,j,k}];
                    a[u][u] += 23;
                    a[u][mp[{ni,j,k}]] += 1;
                    a[u][mp[{i,nj,k}]] += 1;
                    a[u][mp[{i,j,nk}]] += 1;
                }
            }
        }
        
        a = mat_exp(a, n);
        return a[0][m-1];        
    }
};