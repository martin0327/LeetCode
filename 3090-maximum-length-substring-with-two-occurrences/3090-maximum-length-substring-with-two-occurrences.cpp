class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            vector<int> cnt(26);
            for (int j=i; j<n; j++) {
                int x = s[j] - 'a';
                if (++cnt[x] <= 2) ans = max(ans, j-i+1);
                else break;
            }
        }
        return ans;
    }
};