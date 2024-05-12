template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;

const ll inf = 2e9;
class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        vi a(nums.begin(), nums.end());
        ll n = a.size(), ans = inf, full = (1ll<<n)-1;
        vvi _dp;
        ll _i;
        for (int i=0; i<n; i++) {
            vvi dp(1<<n, vi(n, inf));
            dp[1<<i][i] = 0;
            for (ll mask=0; mask<(1<<n); mask++) {
                for (ll j=0; j<n; j++) {
                    if (dp[mask][j] == inf) continue;
                    for (ll nj=0; nj<n; nj++) {
                        if (mask>>nj&1) continue;
                        ll nmask = mask + (1ll<<nj);
                        ll delta = abs(j - a[nj]);
                        chmin(dp[nmask][nj],dp[mask][j] + delta);
                    }
                }
            }
            bool updated = false;
            for (int j=0; j<n; j++) {
                ll t = dp[(1<<n)-1][j] + abs(j-a[i]);
                if (ans > t) {
                    updated = true;
                    ans = t;
                }
            }
            if (updated) {
                _dp = dp;
                _i = i;
            }
        }
        queue<pii> q;
        vvi &dp = _dp;
        ll src = _i;
        
        vvi check(1<<n, vi(n));
        for (int j=0; j<n; j++) {
            if (dp[full][j]+abs(j-a[src]) == ans) {
                q.push({full,j});
                check[full][j] = 1;
            }
        }
        while (q.size()) {
            auto [mask,j] = q.front();
            q.pop();
            for (int nj=0; nj<n; nj++) {
                assert(mask>>j&1);
                if ((mask>>nj&1)) {
                    ll nmask = mask - (1ll<<j);
                    if (check[nmask][nj]) continue;
                    if (dp[nmask][nj] + abs(nj-a[j]) == dp[mask][j]) {
                        q.push({nmask,nj});
                        check[nmask][nj] = 1;
                    }
                }
            }
        }
        
        vp b;
        b.push_back({1<<src,src});
        while (true) {
            auto [mask,j] = b.back();
            if (mask == full) break;
            for (int nj=0; nj<n; nj++) {
                if (mask>>nj&1) continue;
                ll nmask = mask + (1<<nj);
                if (check[nmask][nj]) {
                    ll delta = abs(j - a[nj]);
                    if (dp[nmask][nj] == dp[mask][j] + delta) {
                        b.push_back({nmask,nj});
                        break;
                    }
                }
            }
        }
        vector<int> ret;
        for (auto [mask,j] : b) {
            ret.push_back(j);
        }
        return ret;
    }
};