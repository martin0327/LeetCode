template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
const ll inf = 2e18;

class Solution {
public:
    int minCost(string src, string tg, vector<vector<string>>& rules, vector<int>& costs) {
        int n = src.size(), m = rules.size();
        src = " " + src;
        tg = " " + tg;
        vvp b(n+1);
        for (int l=0; l<m; l++) {
            auto &v = rules[l];
            auto cost = costs[l];

            auto pt = v[0], rp = v[1];
            int sz = pt.size();
            for (auto ch : pt) cost += (ch == '*');
            for (int i=1; i+sz-1<=n; i++) {
                bool ok = true;
                for (int j=0; j<sz; j++) {
                    if (pt[j] != '*' && src[i+j] != pt[j]) ok = false;
                    if (tg[i+j] != rp[j]) ok = false;
                    if (!ok) break;
                }
                if (ok) {
                    b[i+sz-1].push_back({sz,cost});
                }
            }
        }
        vi dp(n+1, inf);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            if (src[i] == tg[i]) {
                chmin(dp[i], dp[i-1]);
            }
            for (auto [sz,cost] : b[i]) {
                if (i-sz >= 0 && dp[i-sz] != inf) {
                    chmin(dp[i], dp[i-sz] + cost);
                }
            }
        }
        auto ans = dp[n];
        if (ans == inf) ans = -1;
        return ans;
    }
};