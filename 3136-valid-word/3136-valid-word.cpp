class Solution {
public:
    bool isValid(string s) {
        string sp = "@#$";
        string vow = "aeiouAEIOU";
        set<char> sc(sp.begin(), sp.end());
        set<char> v(vow.begin(), vow.end());
        bool b1 = (s.size() >= 3);
        bool b2 = false;
        bool b3 = false;
        for (auto c : s) {
            if (sc.count(c)) b1 = false;
            if (v.count(c)) b2 = true;
            if ('a' <= c && c < 'z' && !v.count(c)) b3 = true;
            if ('A' <= c && c < 'Z' && !v.count(c)) b3 = true;
        }
        return b1 && b2 && b3;
    }
};
