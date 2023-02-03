class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        n = s.size();
        int ret = 0;
        for (int i=0; i<n; i++) {
            int x = s[i] - '0';
            ret += ((i&1) ? -1 : 1) * x;
        }
        return ret;
    }
};