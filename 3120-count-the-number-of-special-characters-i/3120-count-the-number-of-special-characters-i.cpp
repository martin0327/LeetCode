class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> a(26);
        for (auto c : s) {
            int x = c - 'a';
            int y = c - 'A';
            auto f = [&] (int x) {
                return 0 <= x && x < 26;
            };
            if (f(x)) a[x] |= 1;
            if (f(y)) a[y] |= 2;
        }
        int ans = 0;
        for (auto x : a) if (x==3) ans++;
        return ans;
    }
};