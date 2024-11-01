class Solution {
public:
    string makeFancyString(string s) {
        string t;
        for (auto c : s) {
            int sz = t.size();
            if (sz < 2 || t.back() != t[sz-2] || t.back() != c) t += c;            
        }
        return t;
    }
};