class Solution {
public:
    string mergeAlternately(string s, string t) {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        string ret;
        while (s.size() || t.size()) {
            if (s.size()) {
                ret += s.back();
                s.pop_back();
            }
            if (t.size()) {
                ret += t.back();
                t.pop_back();
            }
        }
        return ret;
    }
};