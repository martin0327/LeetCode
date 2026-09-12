using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
const ll inf = 2e18;


template<typename T>
void chmax(T &x, T y) {x = max(x,y);}
template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

using S = pair<ll,vi>;
using vS = vector<S>;
using vvS = vector<vS>;

template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& aa) {
        ll n = aa.size();
        vi comp;
        for (int i=0; i<n; i++) {
            auto &v = aa[i];
            ll l = v[0], r = v[1], w = v[2];
            comp.push_back(l);
            comp.push_back(r);
        }
        comp = get_unique(comp);
        ll sz = comp.size();

        auto get_idx = [&] (ll x) {
            auto it = lower_bound(comp.begin(), comp.end(), x);
            ll ret = it - comp.begin() + 1;
            return ret;
        };

        vector<vti3> a(sz+1);
        for (int i=0; i<n; i++) {
            auto &v = aa[i];
            ll l = v[0], r = v[1], w = v[2];
            l = get_idx(l);
            r = get_idx(r);
            a[r].push_back({l,i,w});
        }

        n = sz;
        ll m = 4;
        S init = {inf,{inf}};
        vvS dp(n+1, vS(m+1,init));
        dp[0][0] = {0,{}};
        for (ll i=1; i<=n; i++) {
            dp[i] = dp[i-1];
            for (auto &[l,idx,w] : a[i]) {
                for (ll j=1; j<=m; j++) {
                    if (dp[l-1][j-1].first == inf) continue;
                    auto [val,arr] = dp[l-1][j-1];
                    ll nval = val - w;
                    auto narr = arr;
                    narr.push_back(idx);
                    asort(narr);
                    S tg = {nval,narr};
                    chmin(dp[i][j],tg);
                }
            }
        }
        auto [val,t] = *min_element(dp[n].begin(), dp[n].end());
        vector<int> ans(t.begin(), t.end());
        return ans;
    }
};