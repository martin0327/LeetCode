using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll inf = 1e9;
void chmin(ll &x, ll y) {x = min(x,y);}

class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        ll n = a.size();

        map<ll,ll> mp;
        for (auto x : a) mp[x];
        for (auto x : b) mp[x];
        ll sz = 1;
        for (auto &[k,v] : mp) v = sz++;
        for (auto &x : a) x = mp[x];
        for (auto &x : b) x = mp[x];
        sort(b.begin(), b.end());

        vvi dp(n+1, vi(sz,inf));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<sz; j++) {
                if (dp[i][j] >= inf) continue;
                if (a[i] > j) chmin(dp[i+1][a[i]], dp[i][j]);
                auto it = upper_bound(b.begin(), b.end(), j);
                if (it != b.end()) chmin(dp[i+1][*it], dp[i][j] + 1);
            }
        }
        ll ans = *min_element(dp[n].begin(), dp[n].end());
        if (ans == inf) ans = -1;
        return ans;
    }
};