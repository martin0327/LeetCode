using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;
ll sm(ll x) { 
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
ll mod_sum(ll x, ll y) { return sm(x+y); }
void mod_add(ll &x, ll y) { x = mod_sum(x,y); }
ll mod_mul(ll x, ll y) { return sm(x*y); }
vvi mat_mul(vvi &a, vvi &b) {
    int n = a.size();
    vvi ret(n, vi(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                mod_add(ret[i][j], mod_mul(a[i][k],b[k][j]));
            }
        }
    }
    return ret;
}

vvi mat_exp(vvi a, int e) {
    int n = a.size();
    vvi ret(n, vi(n));
    for (int i=0; i<n; i++) ret[i][i] = 1;
    while (e>0) {
        if (e&1) {
            ret = mat_mul(ret,a);
        }
        a = mat_mul(a,a);
        e >>= 1;
    }
    return ret;
}

class Solution {
public:
    int zigZagArrays(int m, int l, int r) {
        ll n = 2*(r-l+1);
        vvi a(n, vi(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i < n/2) {
                    if (j >= n/2) {
                        if (j-n/2 < i) a[i][j] = 1;
                    }
                }
                else {
                    if (j < n/2) {
                        if (j > i-n/2) a[i][j] = 1;
                    }

                }
            }
        }
        a = mat_exp(a, m-1);
        ll ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                mod_add(ans, a[i][j]);
            }
        }
        return ans;
    }
};