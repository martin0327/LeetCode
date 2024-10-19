class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i=0; i<n-1; i++) {
            string t = s;
            t += '1';
            int m = s.size();
            for (int i=m-1; i>=0; i--) {
                if (s[i] == '0') t += '1';
                else t += '0';
            }
            s = t;
        }
        return s[k-1];
    }
};