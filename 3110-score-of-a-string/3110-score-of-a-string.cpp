class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.size();
        for (int i=1; i<n; i++) {
            int x = s[i] - 'a';
            int y = s[i-1] - 'a';
            ans += abs(x-y);
        }
        return ans;
    }
};