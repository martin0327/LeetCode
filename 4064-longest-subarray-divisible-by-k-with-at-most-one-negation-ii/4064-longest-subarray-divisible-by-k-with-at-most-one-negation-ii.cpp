template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
ll sm(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

class Solution {
public:
    int longestSubarray(vector<int>& aa, int k) {
        vi a(aa.begin(), aa.end());
        int n = a.size();
        a.insert(a.begin(), 0);
        vi d(n+1);
        for (int i=1; i<=n; i++) {
            a[i] = sm(a[i],k);
            d[i] = sm(-2*a[i],k);
        }
        vi pre(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = sm(pre[i-1]+a[i],k);
        }
        ll ans = 0;
        map<ll,ll> mp;
        for (int i=0; i<=n; i++) {
            auto x = pre[i];
            if (mp.count(x)) {
                chmax(ans, i-mp[x]);
            }
            if (!mp.count(x)) mp[x] = i;
        }
        vvi d2i(k), p2i(k);
        for (int i=1; i<=n; i++) {
            d2i[d[i]].push_back(i);
        }
        for (int i=0; i<=n; i++) {
            p2i[pre[i]].push_back(i);
        }
        for (int lval=0; lval<k; lval++) {
            auto &lidx = p2i[lval];
            if (lidx.empty()) continue;
            auto L = lidx.front();
            for (int mval=0; mval<k; mval++) {
                auto &midx = d2i[mval];
                auto it = upper_bound(midx.begin(), midx.end(), L);
                if (it != midx.end()) {
                    auto M = *it;
                    auto tg = sm(lval-mval,k);
                    auto &ridx = p2i[tg];
                    if (ridx.empty()) continue;
                    if (ridx.back() >= M) {
                        auto R = ridx.back();
                        chmax(ans, R-L);
                    }
                }
            }
        }
        return ans;
    }
};