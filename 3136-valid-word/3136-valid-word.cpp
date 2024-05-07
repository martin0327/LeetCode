class Solution {
public:
    bool isValid(string s) {
        string sp = "@#$";
        string vow = "aeiouAEIOU";
        set<char> sc1(sp.begin(), sp.end());
        set<char> sc2(vow.begin(), vow.end());
        bool ans1 = true;
        ans1 &= (s.size() >= 3);
        bool ans2 = false;
        bool ans3 = false;
        for (auto c : s) {
            if (sc1.count(c)) ans1 = false;
            if (sc2.count(c)) ans2 = true;
            int x = c - 'a';
            int y = c - 'A';
            if (0 <= x && x < 26 && !sc2.count(c)) ans3 = true;
            if (0 <= y && y < 26 && !sc2.count(c)) ans3 = true;
        }
        return ans1 && ans2 && ans3;
    }
};
