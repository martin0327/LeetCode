class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int x = 0, y = 0;
        for (auto c : s) x += c == '1';
        for (auto c : t) y += c == '1';
        return !(x>0 ^ y>0);
    }
};