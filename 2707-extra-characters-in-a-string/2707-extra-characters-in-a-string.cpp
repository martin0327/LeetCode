class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size();
        set<string> ss(d.begin(), d.end());
        const int inf = 1e9;
        vector<int> dp(n+1,inf);
        dp[0] = 0;
        s = ' ' + s;
        for (int i=1; i<=n; i++) {
            dp[i] = min(dp[i], dp[i-1]+1);
            for (int j=i; j>0; j--) {
                string t = s.substr(j,i-j+1);
                if (ss.count(t)) {
                    dp[i] = min(dp[i], dp[j-1]);
                }
            }
        }
        return dp[n];
    }
};