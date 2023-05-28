using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
void chmin(int &x, int y) {x = min(x,y);}

class Solution {
public:
    int minCost(int sz, vector<int>& a) {
        a.push_back(0);
        a.push_back(sz);
        sort(a.begin(), a.end());
        int n = a.size()-1;

        vvi dp(n+1, vi(n+1,-1));
        function<int(int,int)> f = [&] (int l, int r) {
            if (l+1==r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            int ret = inf;
            for (int i=l+1; i<r; i++) {
                chmin(ret, a[r]-a[l] + f(l,i) + f(i,r));
            }
            return dp[l][r] = ret;
        };
        
        int ans = f(0,n);
        return ans;
    }
};