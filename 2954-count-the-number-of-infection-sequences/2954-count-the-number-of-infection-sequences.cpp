using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

class Solution {
public:
    
    ll mod_pow(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e&1) ret = (ret * b) % mod;
            b = (b * b) % mod;
            e >>= 1;
        }
        return ret;
    }
    
    int numberOfSequence(int n, vector<int>& a) {
        ll m = a.size();
        ll fr = a.front(), bk = n-1-a.back();
        vi b;
        for (int i=1; i<m; i++) {
            ll x = a[i] - a[i-1] - 1;
            if (x) b.push_back(x);
        }
        vi fact(n+1,1), finv(n+1,1);
        for (int i=1; i<=n; i++) {
            fact[i] = (fact[i-1] * i) % mod; 
        }
        finv[n] = mod_pow(fact[n],mod-2);
        for (int i=n-1; i>=0; i--) {
            finv[i] = (finv[i+1] * (i+1)) % mod;
        }
        
        ll ans = fact[n-m];
        ans = (ans*finv[fr]) % mod;
        ans = (ans*finv[bk]) % mod;
        
        for (auto x : b) {
            ans = (ans * mod_pow(2,x-1)) % mod;
            ans = (ans * finv[x]) % mod;
        }
        
        return ans;
    }
};

