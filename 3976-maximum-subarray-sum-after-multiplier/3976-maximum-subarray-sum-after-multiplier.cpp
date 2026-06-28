template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
const ll inf = 2e18;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vi a(nums.begin(), nums.end());
        int n = a.size();
        a.insert(a.begin(), 0ll);
        vi b(n+1), c(n+1);
        for (int i=1; i<=n; i++) {
            b[i] = a[i] * k;
            c[i] = a[i] / k;
        }
        vi pre(n+1), suf(n+2), s(n+2,0);
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i];
        }
        for (int i=n; i>=1; i--) {
            suf[i] = suf[i+1] + a[i];
        }
        for (ll i=n, mn=0; i>=1; i--) {
            chmax(s[i], suf[i]-mn);
            chmin(mn, suf[i]);
        }

        auto f = [&] (vi b) {
            vi p2(n+1);
            for (int i=1; i<=n; i++) {
                p2[i] = p2[i-1] + b[i];
            }
            ll ret = pre[n];
            for (ll i=1, mn = 0, mx=0; i<=n; i++) {
                chmax(ret, p2[i] + s[i+1] + mx);
                chmin(mn, pre[i]);
                chmax(mx, pre[i] - p2[i] - mn);
            }
            return ret;
        };
        auto ans = max(f(b), f(c));
        return ans;
    }
};