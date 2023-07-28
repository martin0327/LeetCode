using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 1e18;

class Solution {
public:
    bool PredictTheWinner(vector<int>& a) {
        ll n = a.size();
        vvi dp(n, vi(n,inf));

        function<ll(ll,ll)> f = [&] (ll l, ll r) {
            if (l > r) return 0ll;
            if (dp[l][r] != inf) return dp[l][r];
            if ((r-l+1)%2==n%2) return dp[l][r] = max(f(l+1,r)+a[l], f(l,r-1)+a[r]);
            else return dp[l][r] = min(f(l+1,r)-a[l],f(l,r-1)-a[r]);
        };
        
        return f(0,n-1) >= 0;
    }
};