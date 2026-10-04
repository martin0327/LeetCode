class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int cur = 0, ans = 0;
        auto f = [&] (int x, int y) {
            int d = abs(x-y);
            d = min(d, x+10-y);
            d = min(d, y+10-x);
            return d;
        };
        for (auto ch : s) {
            int x = ch - '0';
            ans += f(x,cur);
            cur = x;
        }
        return ans;
    }
};