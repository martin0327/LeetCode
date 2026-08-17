void chmax(int &x, int y) { x = max(x,y); }
using vi = vector<int>;
const int sz = 505;
int pre[sz];
int dp[sz][sz];
bool vis[sz][sz];
class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        memset(pre,0,sizeof(pre));
        pre[0] = a[0];
        for (int i=1; i<n; i++) pre[i] = pre[i-1] + a[i];
        auto g = [&] (int l, int r) {
            int ret = pre[r];
            if (l > 0) ret -= pre[l-1];
            return ret;
        };
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        function<int(int,int)> f = [&] (int l, int r) {
            int ret = 0;
            if (vis[l][r]) return dp[l][r];
            vis[l][r] = 1;
            if (l == r) return dp[l][r] = ret;
            for (int i=l; i<r; i++) {
                auto v1 = g(l,i), v2 = g(i+1,r);
                int t = 0;
                if (v1 < v2) {
                    t = v1 + f(l,i);
                }
                else if (v1 > v2) {
                    t = v2 + f(i+1,r);
                }
                else {
                    t = max(f(l,i), f(i+1,r)) + v1;
                }
                chmax(ret, t);
            }
            return dp[l][r] = ret;
        };
        auto ans = f(0,n-1);
        return ans;
    }
};