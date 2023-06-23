using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
void chmax(ll &x, ll y) {x = max(x,y);}
class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        ll n = a.size(), m = 500;
        vvi dp(m+1, vi(m+1));
        ll ans = 2;
        for (int j=0; j<n; j++) {
            ll z = a[j];
            vi t(m+1);
            for (int i=0; i<j; i++) {
                ll y = a[i];
                ll d = z - y;
                ll x = y - d;
                if (0 <= x && x <= m) chmax(t[y],dp[y][x]+1);
                chmax(t[y],2ll);
                chmax(ans,t[y]);
            }
            dp[z] = t;
        }
        return ans;        
    }
};