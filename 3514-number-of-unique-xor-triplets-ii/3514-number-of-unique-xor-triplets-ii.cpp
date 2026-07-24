using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n = a.size();
        int sz = -1;
        for (auto &x : a) {
            for (int i=0; i<15; i++) {
                if (x>>i&1) {
                    sz = max(sz, i);
                }
            }
        }
        int m = (1<<(sz+1));
        vi dp(m);
        dp[0] = 1;
        int t = 3;
        while (t--) {
            vi ndp(m);
            for (auto &x : a) {
                for (int i=0; i<m; i++) {
                    if (dp[i]) {
                        ndp[i^x] = 1;
                    }
                }
            }
            swap(dp,ndp);
        }
        int ans = 0;
        for (auto &x : dp) {
            if (x) ans++;
        }
        return ans;
    }
};