using ll = long long ;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int n,k;
    vector<vector<int>> a;
    vvi dp;

    ll f(int i, int j) {
        if (i==n) return 0;
        if (j==0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        ll ret = f(i+1,j);
        ll pre = 0;
        for (int l=0; l<a[i].size(); l++) {
            if (j<l+1) continue;
            pre += a[i][l];
            ret = max(ret, pre+f(i+1,j-l-1));
        } 
        return dp[i][j] = ret;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int _k) {
        n = piles.size();
        k = _k;
        a = piles;
        dp.assign(n, vi(k+1,-1));
        ll ans = f(0,k);
        return (int) ans;
    }
};