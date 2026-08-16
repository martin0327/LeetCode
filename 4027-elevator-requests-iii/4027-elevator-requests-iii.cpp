template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 2e18;
class Solution {
public:
    long long elevatorRequests(int m, int start, vector<vector<int>>& a) {
        a.insert(a.begin(), {0,start});
        int n = a.size();
        vvi dp(1<<n, vi(n, inf));
        dp[1][0] = 0;
        for (int mask=0; mask<(1<<n); mask++) {
            for (int i=0; i<n; i++) {
                if (dp[mask][i] == inf) continue;
                for (int j=0; j<n; j++) {
                    if (mask>>j&1) continue;
                    int nmask = mask | (1<<j);
                    ll d = abs(a[i][1] - a[j][1]);
                    ll val = dp[mask][i] + d;
                    chmax(val, a[j][0]);
                    chmin(dp[nmask][j], val);
                }
            }
        }
        ll ans = inf;
        for (int i=0; i<n; i++) {
            chmin(ans, dp[(1<<n)-1][i]);
        }
        return ans;
    }
};