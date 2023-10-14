class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& s, vector<int>& g) {
        vector<int> par(n,-1), dp(n,1);
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (g[i] != g[j]) {
                    if (s[i].size() == s[j].size()) {
                        int cnt = 0;
                        for (int l=0; l<s[i].size(); l++) {
                            cnt += (s[i][l] != s[j][l]);
                        }
                        if (cnt == 1) {
                            if (dp[j] >= dp[i]) {
                                dp[i] = dp[j]+1;
                                par[i] = j;
                            }
                        }
                    }
                }
            }
        }
        int mx = 0, idx = -1;
        for (int i=0; i<n; i++) {
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }
        vector<string> ret;
        while (idx != -1) {
            ret.push_back(s[idx]);
            idx = par[idx];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};