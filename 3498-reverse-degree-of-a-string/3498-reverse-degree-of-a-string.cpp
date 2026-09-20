class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            int x = s[i] - 'a';
            x = 26 - x;
            ans += x * (i+1);
        }
        return ans;
    }
};