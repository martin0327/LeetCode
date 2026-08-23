class Solution {
public:
    bool isPalindromic(string s) {
        string t;
        for (auto ch : s) {
            int x = ch;
            auto f = [&] (int x) {
                string ret;
                for (int i=0; i<8; i++) {
                    ret += '0' + (x&1);
                    x >>= 1;
                }
                reverse(ret.begin(), ret.end());
                return ret;
            };
            t += f(x);
        }
        int n = t.size();
        for (int i=0; i<n; i++) {
            if (t[i] != t[n-1-i]) return false;
        }
        return true;
    }
};