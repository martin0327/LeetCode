class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size();
        for (int i=n-1; i>=0; i--) {
            if ((s[i]-'0')&1) return s.substr(0,i+1);
        }
        return "";
    }
};