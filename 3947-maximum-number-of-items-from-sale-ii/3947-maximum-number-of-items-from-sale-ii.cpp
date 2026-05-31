template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<int>;
const int inf = 2e9;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& a, int k) {
        int n = a.size(), minp = inf;
        vi frq(n+1);
        for (auto &v : a) {
            int f = v[0], p = v[1];
            frq[f]++;
            chmin(minp, p);
        }
        vi b(n+1);
        for (int i=1; i<=n; i++) {
            for (int j=i; j<=n; j+=i) {
                b[i] += frq[j];
            }
        }
        map<int,ll> mp;
        for (auto &v : a) {
            int f = v[0], p = v[1];
            auto cnt = b[f] - 1;
            if (cnt > 0  && p <= 2*minp) mp[p] += cnt;
        }

        int ans = 0;
        for (auto &[p,cnt] : mp) {
            chmin(cnt, k / p);
            ans += 2*cnt;
            k -= p*cnt;
        }
        ans += k / minp;
        return ans;
    }
};