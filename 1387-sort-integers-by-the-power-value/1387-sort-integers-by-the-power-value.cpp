using vi = vector<int>;
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        int n = 1e6;
        vi dp(n+1, -1);
        function<int(int)> f = [&](int x) {
            if (dp[x] != -1) return dp[x];
            if (x==1) return dp[x] = 0;
            if (x&1) return dp[x] = 1+f(3*x+1);
            else return dp[x] = 1+f(x/2);
        };
        vector<pair<int,int>> a;
        for (int i=lo; i<=hi; i++) a.emplace_back(f(i),i);
        sort(a.begin(), a.end());
        return a[k-1].second;
    }
};