class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        int i = n-1, j = m-1;
        int ci = 0, cj = 0;
        
        while (i >=0 || j >= 0) {
            while (i >= 0) {
                if (s[i]=='#') {
                    ci++; i--;
                }
                else if (ci > 0) {
                    ci--; i--;
                }
                else break;
            }
            while (j >= 0) {
                if (t[j]=='#') {
                    cj++; j--;
                }
                else if (cj > 0) {
                    cj--; j--;
                }
                else break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] == t[j]) {
                    i--; j--;
                }
                else return false;
            }
            else if (i >= 0) return false;
            else if (j >= 0) return false;
        }
        return true;
    }
};