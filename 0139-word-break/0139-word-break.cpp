class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = 0;
        set<string> ss;
        for (auto t : wordDict) {
            ss.insert(t);
            m = max(m, (int)t.size());
        }
        s.insert(s.begin(), ' ');
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            if (!dp[i]) continue;
            for (int j=1; j<=m && i+j<=n; j++) {
                if (ss.count(s.substr(i+1,j))) dp[i+j] = 1;
            }
        }
        return dp[n];
    }
};