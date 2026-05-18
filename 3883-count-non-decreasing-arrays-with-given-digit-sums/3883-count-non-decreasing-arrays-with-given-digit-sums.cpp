
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;
const int sz = 51, mod = 1e9+7;
const int maxn = 1001, maxm = 400;
vi b[sz];
int dp[maxn][maxm];

class Solution {
public:
    int countArrays(vector<int>& a) {
        int n = a.size(), m = maxm;
        for (int i=0; i<sz; i++) b[i].clear();
        for (int i=0; i<5001; i++) {
            auto f = [&] (int x) {
                int ret = 0;
                while (x > 0) {
                    ret += x % 10;
                    x /= 10;
                }
                return ret;
            };
            b[f(i)].push_back(i);
        }
        // memset(dp[0], 0, sizeof(dp[0]));
        vvi dp(n, vi(m));
        for (int j=0; j<b[a[0]].size(); j++) {
            dp[0][j] = 1;
        }
        for (int i=1; i<n; i++) {
            // memset(dp[i], 0, sizeof(dp[i]));
            auto &v1 = b[a[i-1]];
            auto &v2 = b[a[i]];
            int sz1 = v1.size();
            int sz2 = v2.size();
            for (int j=0; j<sz1; j++) {
                auto x = v1[j];
                auto it = lower_bound(v2.begin(), v2.end(), x);
                int nj = it - v2.begin();
                if (nj < sz2) {
                    dp[i][nj] += dp[i-1][j];
                    dp[i][nj] %= mod;
                }
            }
            for (int j=1; j<sz2; j++) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
        ll ans = 0;
        for (int j=0; j<b[a.back()].size(); j++) {
            ans += dp[n-1][j];
            ans %= mod;
        }
        return ans;
    }
};
