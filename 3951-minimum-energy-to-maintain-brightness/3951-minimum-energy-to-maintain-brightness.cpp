template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}

using ll = long long;
using pii = pair<ll,ll>;
using vp = vector<pii>;

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

class Solution {
public:
    long long minEnergy(ll n, ll br, vector<vector<int>>& itv) {
        vp b;
        for (auto &v : itv) {
            ll l = v[0], r = v[1];
            b.push_back({l,r});
        }
        asort(b);
        vp a;
        for (auto [l,r] : b) {
            if (a.empty()) a.push_back({l,r});
            else {
                if (l <= a.back().second) {
                    chmax(a.back().second, r);
                }
                else a.push_back({l,r});
            }
        }
        auto x = ceil_div(br,3);
        ll ans = 0;
        for (auto [l,r] : a) {
            ans += x * (r-l+1);
        }
        return ans;
    }
};