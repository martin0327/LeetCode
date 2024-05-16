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
        ll src = 0; // there always exists an optimal permutation that starts with 0.
        
        vvi dp(1<<n, vi(n, inf));
        dp[1<<src][src] = 0; // 1<<src is the bitmask expressing {0} <- only index 0 is selected
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

        for (int j=0; j<n; j++) {
            chmin(ans, dp[full][j] + abs(j-a[src]));
        }
        
        queue<pii> q;        
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
                    ll pmask = mask - (1<<j);
                    if (check[pmask][nj]) continue;
                    if (dp[pmask][nj] + abs(nj-a[j]) == dp[mask][j]) {
                        q.push({pmask,nj});
                        check[pmask][nj] = 1;
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