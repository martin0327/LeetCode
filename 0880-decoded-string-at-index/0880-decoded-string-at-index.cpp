class Solution {
public:
    string decodeAtIndex(string s, int k) {
        using ll = long long;
        ll sz = 0;
        for (auto c : s) {
            if (isdigit(c)) sz *= c - '0';
            else sz++;
        }
        reverse(s.begin(), s.end());
        for (auto c : s) {
            if (sz==k) {
                if (isdigit(c)) {
                    int x = c - '0';
                    sz /= x;
                    k /= x;
                }
                else {
                    return string(1,c);
                }
            }
            else {
                if (isdigit(c)) {
                    int x = c - '0';
                    sz /= x;
                    if (k > sz) k %= sz;
                    if (k==0) k += sz;
                }
                else {
                    sz--;
                }
            }
        }
        return "";
        
    }
};