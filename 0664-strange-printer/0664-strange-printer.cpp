const int inf = 1e9;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int strangePrinter(string s) {
        string t;
        for (auto c : s) {
            if (t.empty() || t.back() != c) {
                t += c;
            }
        }
        int n = t.size();
        vvi dp(n, vi(n,-1));
        
        function<int(int,int)> f = [&](int l, int r) {
            if (l==r) return 1;
            if (dp[l][r] != -1) return dp[l][r];
            int ret = inf;
            for (int i=l; i<r; i++) {
                int temp = f(l,i) +f(i+1,r);
                if (t[l]==t[r]) temp--;
                ret = min(ret,temp);
            }
            return dp[l][r] = ret;
        };
        int ans = f(0,n-1);
        return ans;
    }
};