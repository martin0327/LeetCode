template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
const int inf = 2e9;
class Solution {
public:
    int maxScore(vector<vector<int>>& a) {
        auto f = [&] (vector<int> &a) {
            int n = a.size(), ret = -inf;
            int cum = 0, mn = 0;
            for (int i=0; i<n; i++) {
                cum += a[i];
                if (i > 0) chmax(ret,cum-mn);
                if (i+1 < n-1) chmin(mn, cum);
            }
            return ret;
        };

        auto g = [&] (vector<int> &a) {
            int n = a.size(), ret = -inf;
            vector<int> pre(n+1);
            for (int i=0; i<n; i++) {
                pre[i+1] = pre[i] + a[i];
            }
            for (int i=2,mn=0; i<=n; i++) {
                chmax(ret, pre[i]-mn);
                chmin(mn, pre[i-1]);
            }
            return ret;
        };

        auto vslice = [&] (int j) {
            int n = a.size();
            vector<int> ret(n);
            for (int i=0; i<n; i++) {
                ret[i] = a[i][j];
            }
            return ret;
        };

        int n = a.size(), m = a[0].size();
        int ans = -inf;
        for (int i=1; i+1<n; i++) {
            chmax(ans, f(a[i]));
        }
        for (int j=1; j+1<m; j++) {
            auto b = vslice(j);
            chmax(ans, f(b));
        }

        chmax(ans, g(a[0]));
        chmax(ans, g(a[n-1]));
        auto b = vslice(0);
        chmax(ans, g(b));
        b = vslice(m-1);
        chmax(ans, g(b));

        return ans;
    }
};
