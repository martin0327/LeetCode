class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            int x = s[i] - 'a';
            for (int j=i; j<i+26; j++) {
                int y = s[j] - 'a';
                if (y-x == j-i) ans = max(ans, j-i+1);
                else break;
            }
        }
        return ans;
        
    }
};