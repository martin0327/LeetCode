template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    long long minInitialStrength(vector<int>& a, vector<vector<int>>& b) {
        int n = a.size();
        vi p(n+1);
        for (auto &v : b) {
            ll l = v[0], r = v[1], w = v[2];
            p[l] += w;
            p[r+1] -= w;
        }
        for (int i=1; i<=n; i++) {
            p[i] += p[i-1];
        }
        ll lo = 0, hi = 1e16, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll cur = mid;
            bool ok = true;
            for (int i=0; i<n; i++) {
                if (cur + p[i] >= a[i]) {
                    cur -= a[i];
                    chmax(cur, 0);
                }
                else ok = false;
            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};
