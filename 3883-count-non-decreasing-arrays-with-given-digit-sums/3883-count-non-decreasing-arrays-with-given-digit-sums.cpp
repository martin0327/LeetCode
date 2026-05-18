using ll = long long;
using vi = vector<ll>;
const int sz = 51, mod = 1e9+7;
const int maxn = 1001, maxm = 400;
vi b[sz];
int dp[maxn][maxm];

class Solution {
public:
    int countArrays(vector<int>& a) {
        if (b[0].empty()) {
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
        }
        
        int n = a.size(), m = maxm;        
        for (int i=0; i<n; i++) {
            memset(dp[i], 0, sizeof(dp[i]));
            if (i == 0) {
                for (int j=0; j<b[a[i]].size(); j++) {
                    dp[0][j] = 1;
                }
                continue;
            }
            auto &v1 = b[a[i-1]], &v2 = b[a[i]];
            int sz1 = v1.size(), sz2 = v2.size();
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