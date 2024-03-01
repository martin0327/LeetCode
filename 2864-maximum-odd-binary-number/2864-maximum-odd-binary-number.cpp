class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c0 = 0, c1 = 0;
        for (auto c : s) {
            if (c=='1') c1++;
            else c0++;
        }
        string ans;
        c1--;
        while (c1--) ans += '1';
        while (c0--) ans += '0';
        ans += '1';
        return ans;
    }
};