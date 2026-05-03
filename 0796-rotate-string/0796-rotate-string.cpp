class Solution {
public:
    bool rotateString(string s, string t) {
        int n = s.size();
        s = s + s;
        for (int i=0; i<n; i++) {
            if (t == s.substr(i,n)) return true;
        }
        return false;
    }
};