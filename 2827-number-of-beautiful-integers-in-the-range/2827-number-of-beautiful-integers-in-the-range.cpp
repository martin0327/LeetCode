using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        vi a,b;
        for (auto c : to_string(high)) a.push_back(c-'0');
        for (auto c : to_string(low-1)) b.push_back(c-'0');

        auto f = [&](vi &a) {
            ll n = a.size();
            vector dp(n+1, vector (2*n+1, vvvi(k, vvi(2,vi(2)))));
            dp[0][n][0][0][0] = 1;
            vi tens(n,1);
            for (int i=n-2; i>=0; i--) tens[i] = tens[i+1] * 10;
            for (int i=0; i<n; i++) {
                for (ll j=0; j<=2*n; j++) {
                    for (ll l=0; l<k; l++) {
                        for (ll h=0; h<2; h++) {
                            for (ll z=0; z<2; z++) {
                                for (ll p=0; p<=(h?9:a[i]); p++) {
                                    if (dp[i][j][l][h][z]==0) continue;
                                    ll nj = j;
                                    if (z==0 && p==0) nj += 0;
                                    else if (p&1) nj += 1;
                                    else nj -= 1;
                                    ll nl = (l+p*tens[i])%k;
                                    ll nh = h | (p<a[i]);
                                    ll nz = z | (p!=0);
                                    if (nj < 0 || nj >2*n) continue;
                                    dp[i+1][nj][nl][nh][nz] += dp[i][j][l][h][z];

                                }
                            }
                        }
                    }
                }
            }
            ll ret = 0;
            for (int h=0; h<2; h++) {
                for (int z=0; z<2; z++) {
                    ret += dp[n][n][0][h][z];
                }
            }
            return ret;
        };

        ll ans = f(a) - f(b);
        return ans;
    }
};