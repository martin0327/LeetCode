class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for (int i=1; i<n; i++) {
            int x = s[i-1] - '0';
            int y = s[i] - '0';
            if (abs(x-y) > 2) return false;
        }
        return true;
    }
};