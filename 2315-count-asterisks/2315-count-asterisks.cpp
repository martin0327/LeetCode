class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        int ans = 0;
        for (auto c : s) {
            if (c == '|') cnt++;
            if (c == '*') {
                if (cnt%2==0) ans++;
            }
        }
        return ans;
    }
};