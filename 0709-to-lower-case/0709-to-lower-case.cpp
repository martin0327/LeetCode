class Solution {
public:
    string toLowerCase(string s) {
        for (auto &c : s) {
            int x = c - 'A';
            if (0 <= x && x < 26) c += 'a' - 'A';
        }
        return s;
    }
};