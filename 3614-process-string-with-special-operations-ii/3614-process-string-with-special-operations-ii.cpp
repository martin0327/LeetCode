using ll = long long;
class Solution {
public:
    char processStr(string s, long long k) {
        ll n = s.size(), m = 0;
        for (auto &ch : s) {
            if (ch == '*') {
                if (m > 0) m--;
            }
            else if (ch == '#') m <<= 1;
            else if (ch != '%') m++;
        }
        if (k < 0 || k >= m) return '.';
        for (int i=n-1; i>=0; i--) {
            auto ch = s[i];
            if (ch == '*') m++;
            else if (ch == '#') {
                m >>= 1;
                if (k >= m) k -= m;
            }
            else if (ch == '%') {
                k = m-1-k;
            }
            else {
                if (k == m-1) return s[i];
                m--;
            }
        }
        return '.';
    }
};