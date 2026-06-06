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
    long long maxTotal(vector<int>& nums, string s) {
        vi a(nums.begin(), nums.end());
        int n = a.size();
        vvi dp(n, vi(2,-inf));
        if (s[0] == '1') {
            dp[0][1] = a[0];
        }
        else dp[0][0] = 0;
        for (int i=1; i<n; i++) {
            if (s[i] == '1') {
                chmax(dp[i][0],dp[i-1][0]+a[i-1]);
                chmax(dp[i][1],max(dp[i-1][0],dp[i-1][1])+a[i]);
            }
            else {
                chmax(dp[i][0],max(dp[i-1][0],dp[i-1][1]));
            }
        }
        auto ans = max(dp[n-1][0],dp[n-1][1]);
        return ans;
    }
};