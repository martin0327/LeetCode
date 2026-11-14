template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
using vd = vector<ld>;
using vvd = vector<vd>;
const ld inf = 2e18;
class Solution {
public:
    double largestSumOfAverages(vector<int> &a, int k) {
        int n = a.size();
        vi pre(n+1);
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + a[i];
        }
        vvd dp(k+1, vd(n+1,-inf));
        dp[0][0] = 0;
        for (int i=0; i<k; i++) {
            for (int j=0; j<n; j++) {
                if (dp[i][j] < 0) continue;
                for (int nj=j+1; nj<=n; nj++) {
                    ld avg = pre[nj] - pre[j];
                    avg /= (ld) (nj-j);
                    chmax(dp[i+1][nj], dp[i][j] + avg);
                }
            }
        }
        
        ld ans = 0;
        for (int i=1; i<=k; i++) {
            chmax(ans, dp[i][n]);
        }
        return ans;
    }
};