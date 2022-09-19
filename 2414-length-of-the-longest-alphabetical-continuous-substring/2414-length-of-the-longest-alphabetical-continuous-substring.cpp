class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int ans = 1;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<i+26; j++) {
                if (s[j]-s[i] == j-i) ans = max(ans, j-i+1);
                else break;
            }
        }
        return ans;
    }
};