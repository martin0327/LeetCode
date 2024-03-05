class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while (i < j) {
            char c = s[i];
            if (s[j] == c) {
                while (i<n && s[i] == c) i++;
                while (j>=0 && s[j] == c) j--;
            }
            else break;
        }
        int ans = max(0,j-i+1);
        return ans;
    }
};