class Solution {
public:
    int minRotations(int n, string s) {
        s = "0" + s;
        int base = 0;
        auto f = [&] (char xx, char yy) {
            int x = xx - '0';
            int y = yy - '0';
            int d = abs(x-y);
            d = min(d, x+10-y);
            d = min(d, y+10-x);
            return d;
        };
        for (int i=1; i<=n; i++) {
            base += f(s[i],s[i-1]);
        }
        auto ans = base;
        for (int i=1; i<=n; i++) {
            auto x = f(s[i-1],s[i]);
            auto y = f(s[i-1],s.back());
            ans = min(ans, base-x+y);
        }
        return ans;
    }
};