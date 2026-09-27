template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;

const ll inf = 2e18;
class Solution {
public:
    long long maxEarnings(vector<vector<int>>& a) {
        vi cx;
        for (auto &v : a) {
            auto l = v[0], r = v[1], w = v[2];
            cx.push_back(l);
            cx.push_back(r);
        }
        cx = get_unique(cx);
        auto g = [&] (ll x) {
            auto it = lower_bound(cx.begin(), cx.end(), x);
            return it - cx.begin();
        };
        int sz = cx.size();
        vvp b(sz);
        vi dp(sz,-inf);
        for (auto &v : a) {
            auto l = v[0], r = v[1], w = v[2];
            l = g(l);
            r = g(r);
            b[r].push_back({l,w});
            chmax(dp[r],w);
        }
        ll ans = -inf;
        for (int i=0; i<sz; i++) {
            for (auto [l,w] : b[i]) {
                auto d = cx[i] - cx[l];
                chmax(dp[i],dp[l]+w);
            }
            chmax(ans, dp[i]);
            if (i > 0) {
                auto d = cx[i] - cx[i-1];
                chmax(dp[i],dp[i-1]+d);
            }
        }
        return ans;
    }
};