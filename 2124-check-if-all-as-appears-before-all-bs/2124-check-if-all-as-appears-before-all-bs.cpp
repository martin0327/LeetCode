class Solution {
public:
    bool checkString(string s) {
        set<char> ss;
        for (auto x : s) {
            if (x=='a') {
                if (ss.count('b')) {
                    return false;
                }
            }
            ss.insert(x);
        }
        return true;
    }
};