class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n==1) return false;
        for (int i=1; i<n; i++) {
            if (n % i == 0) {
                string t = s.substr(0,i);
                string u;
                while (u.size() < n) u += t;
                if (u==s) return true;
            }
        }
        return false;
    }
};