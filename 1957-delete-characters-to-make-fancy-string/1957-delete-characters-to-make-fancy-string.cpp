class Solution {
public:
    string makeFancyString(string s) {
        string t;
        for (auto c : s) {
            int sz = t.size();
            if (sz < 2 || t.substr(sz-2,2) != string(2,c)) t += c;            
        }
        return t;
    }
};