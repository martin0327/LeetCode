class Solution {
public:
    bool checkValidString(string s) {
        int l=0,r=0,w=0;
        for (auto c : s) {
            if (c == '*') w++;
            else if (c == ')') r++;
            else l++;
        }

        if (r < l) {
            int t = '(' ^ ')';
            for (auto &c : s) {
                if (c != '*') c ^= t;
            }
            reverse(s.begin(), s.end());
            swap(l,r);
        }

        int d = r - l;
        if (d > w) return false;
        for (auto &c : s) {
            if (c == '*' && d > 0) {
                c = '(';
                d--;
                w--;
                l++;
            }
        }
        int h = w / 2;
        for (auto &c : s) {
            if (c == '*' && h > 0) {
                c = '(';
                h--;
            }
        }
        reverse(s.begin(), s.end());
        h = w / 2;
        for (auto &c : s) {
            if (c == '*' && h > 0) {
                c = ')';
                h--;
            }
        }
        reverse(s.begin(), s.end());
        int x = 0;
        for (auto c : s) {
            if (c == '(') x++;
            else if (c == ')') x--;
            if (x < 0) return false;
        }
        return true;

    }
};