class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        using ll = long long;
        using pii = pair<ll,ll>;
        using vp = vector<pii>;
        const ll inf = 1e9;
        ll n = a.size();
        vp dp(n);
        for (int j=0; j<n; j++) {
            ll x = a[j];
            ll mx = -inf, cnt = 0;
            dp[j] = {1,1};
            for (int i=0; i<j; i++) {
                if (a[i] >= a[j]) continue;
                auto [l,c] = dp[i];
                if (l > mx) {
                    mx = l;
                    cnt = c;
                }
                else if (l==mx) cnt += c;
            }
            if (mx > -inf) dp[j] = {mx+1,cnt};
        }
        ll mx = -inf, ans = 0;
        for (auto [l,c] : dp) {
            if (l > mx) {
                mx = l;
                ans = c;
            }
            else if (l == mx) ans += c;
        }
        return ans;
    }
};
