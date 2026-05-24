class Solution {
public:
    int passwordStrength(string s) {
        set<char> t(s.begin(), s.end());
        set<char> sc;
        {
            string t = "!@#$";
            sc = set<char>(t.begin(), t.end());
        }
        int ans = 0;
        auto f = [&] (int x, int l, int r) {
            return l <= x && x < r;
        };
        for (auto ch : t) {
            if (f(ch-'a',0,26)) ans += 1;
            if (f(ch-'A',0,26)) ans += 2;
            if (f(ch-'0',0,10)) ans += 3;
            if (sc.count(ch)) ans += 5;
        }
        return ans;
    }
};