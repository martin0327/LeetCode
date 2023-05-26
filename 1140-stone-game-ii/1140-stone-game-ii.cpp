using ll = long long;
using vi = vector<ll>;
const ll inf = 1e9;
void chmax(ll &x, ll y) {x = max(x,y);}
void chmin(ll &x, ll y) {x = min(x,y);}

class Solution {
public:
    ll dp[101][2][101];
    int stoneGameII(vector<int>& a) {
        int n = a.size();
        memset(dp,-1,sizeof(dp));
        
        vi pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
        
        function<ll(ll,ll,ll)> f = [&](ll i, ll j, ll k) {
            if (i >= n) return 0ll;
            if (dp[i][j][k] != -1) return dp[i][j][k];
            ll ret = (j&1) ? inf : 0;
            for (ll x=1; x<=2*k; x++) {
                ll ni = i+x;
                ll nj = j^1;
                ll nk = max(k,x);
                if (ni > n) break;
                if (nj&1) chmax(ret, f(ni,nj,nk) + pre[i+x] - pre[i]);
                else chmin(ret, f(ni,nj,nk));
            }
            return dp[i][j][k] = ret;
        };
        return f(0,0,1);        
    }
};