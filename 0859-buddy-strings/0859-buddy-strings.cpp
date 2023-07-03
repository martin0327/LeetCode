class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;
        
        if (s==t) {
            set<char> sc(s.begin(), s.end());
            if (sc.size() != n) return true;
        }
        
        string x,y;
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) {
                x += s[i];
                y += t[i];
            }
        }
        if (x.size()==2) {
            reverse(x.begin(), x.end());
            if (x==y) return true;
        }
        return false;
    }
};