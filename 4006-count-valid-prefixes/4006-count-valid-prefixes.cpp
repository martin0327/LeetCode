class Solution {
public:
    int countValidPrefixes(string s) {
        int x = 0, y = 0, ans = 0;
        for (auto ch : s) {
            if (ch == '0') x++;
            else y++;
            if (abs(x-y) <= 1) ans++;
        }
        return ans;
    }
};