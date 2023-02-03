class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int n = s.size();
        int cnt = 0, cnt2 = 0;
        for (auto c : s) cnt += c == '1';
        for (auto c : t) cnt2 += c == '1';
        if (cnt) {
            if (cnt2) return true;
            else return false;
        }
        else {
            if (cnt2) return false;
            else return true;
        }
        return true;
    }
};