class Solution {
public:
    int minLength(string s) {
        string t;
        for (auto c : s) {
            if (t.empty()) t += c;
            else if (t.back() == 'A' && c == 'B') {
                t.pop_back();
            }
            else if (t.back() == 'C' && c == 'D') {
                t.pop_back();
            }
            else t += c;
        }
        int ans = t.size();
        return ans;
    }
};