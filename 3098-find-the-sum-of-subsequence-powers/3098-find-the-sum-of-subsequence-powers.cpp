
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll mod = 1e9+7;

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

void mod_sum(ll &x, ll y) {
    x = safe_mod(x+y,mod);
}

class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        vi a(nums.begin(), nums.end());
        ll n = a.size();
        a.push_back(-1e9);
        sort(a.begin(), a.end());
        vi diffs;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                int d = a[j] - a[i];
                if (d > 0) diffs.push_back(d);
            }
        }
        sort(diffs.begin(), diffs.end());
        diffs.erase(unique(diffs.begin(), diffs.end()), diffs.end());

        int dsz = diffs.size();
        vvi lower_idx(dsz,vi(n, n+1));
        auto upper_idx = lower_idx;
        for (int di=0; di<dsz; di++) {
            int d = diffs[di];
            for (int i=0, j=0; i<n; i++) {
                while (j <= n && a[j]-a[i] < d) j++;
                if (j <= n && a[j]-a[i] >= d) lower_idx[di][i] = j;
            }
            for (int i=0, j=0; i<n; i++) {
                while (j<=n && a[j]-a[i] <= d) j++;
                if (j <= n && a[j]-a[i] > d) upper_idx[di][i] = j;
            }
        }
        vvvi dp(n+1, vvi(k+1, vi(2)));
        auto pre = dp;
        
        ll ans = 0;
        for (int di=0; di<dsz; di++) {
            ll d = diffs[di];
            for (int i=0; i<=n; i++) {
                for (int j=0; j<=k; j++) {
                    for (int l=0; l<2; l++) {
                        dp[i][j][l] = pre[i][j][l] = 0;
                    }
                }
            }
            dp[0][0][0] = 1;
            
            for (int i=0; i<=n; i++) {
                for (int j=0; j<=k; j++) {
                    for (int l=0; l<2; l++) {
                        if (i > 0) {
                            mod_sum(pre[i][j][l],pre[i-1][j][l]);
                            mod_sum(dp[i][j][l],pre[i][j][l]);
                        }
                        if (dp[i][j][l] == 0) continue;
                        if (i < n && j < k) {
                            int ni = lower_idx[di][i];
                            if (ni > n) continue;
                            ll w = a[ni] - a[i];
                            if (l==1 || w > d) mod_sum(pre[ni][j+1][l],dp[i][j][l]);
                            else {
                                mod_sum(pre[ni][j+1][1],dp[i][j][l]);
                                int ni2 = upper_idx[di][i];
                                if (ni2 <= n) {
                                    mod_sum(pre[ni2][j+1][1],-dp[i][j][l]);
                                    mod_sum(pre[ni2][j+1][0],dp[i][j][l]);
                                }
                            }
                        }
                    }
                }
            }
            for (int i=k; i<=n; i++) {
                mod_sum(ans,d*dp[i][k][1]);
            }
        }
        return ans;
    }
};