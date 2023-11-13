class Solution {
public:
    string sortVowels(string s) {
        string t = "aeiouAEIOU";
        set<char> sc(t.begin(), t.end());
        t.clear();
        for (auto c : s) {
            if (sc.count(c)) {
                t += c;
            }
        }
        sort(t.rbegin(), t.rend());
        for (auto &c : s) {
            if (sc.count(c)) {
                c = t.back();
                t.pop_back();
            }
        }
        return s;
    }
};