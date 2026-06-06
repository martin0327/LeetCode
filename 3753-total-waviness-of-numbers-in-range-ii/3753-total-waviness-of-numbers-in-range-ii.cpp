using ll = long long;
using vi = vector<ll>;
const int sz = 20;
ll dp[sz][2][2][3][10][sz];
class Solution {
public:
    long long totalWaviness(long long lo, long long hi) {
        function<ll(ll)> f = [&] (ll z) {
            auto s = to_string(z);
            ll ret = 0, n = s.size();
            vi a(n);
            for (int i=0; i<n; i++) a[i] = s[i] - '0';
            memset(dp,0,sizeof(dp));
            dp[0][0][0][0][0][0] = 1;
            for (int i=0; i<n; i++) {
                for (int tb=0; tb<2; tb++) {
                    for (int lz=0; lz<2; lz++) {
                        for (int j=0; j<3; j++) {
                            for (int l=0; l<10; l++) {
                                for (int cnt=0; cnt<sz; cnt++) {
                                    if (dp[i][tb][lz][j][l][cnt] == 0) continue;
                                    for (int d=0; d<=(tb?9:a[i]); d++) {
                                        int ntb = tb | (d < a[i]);
                                        int nlz = lz | (d != 0);
                                        int nj = 0;
                                        if (lz && d != l) nj = (d<l) ? 1 : 2;
                                        int nl = d;
                                        int ncnt = cnt + (j+nj==3);
                                        dp[i+1][ntb][nlz][nj][nl][ncnt] += dp[i][tb][lz][j][l][cnt];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int tb=0; tb<2; tb++) {
                for (int lz=0; lz<2; lz++) {
                    for (int j=0; j<3; j++) {
                        for (int l=0; l<10; l++) {
                            for (int cnt=1; cnt<sz; cnt++) {
                                ret += dp[n][tb][lz][j][l][cnt] * cnt;
                            }
                        }
                    }
                }
            }
            return ret;
        };
        auto ans = f(hi) - f(lo-1);
        return ans;
    }
};