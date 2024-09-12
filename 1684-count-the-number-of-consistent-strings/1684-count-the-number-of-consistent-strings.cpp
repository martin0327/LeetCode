class Solution {
public:
    int countConsistentStrings(string s, vector<string>& a) {
        set<char> sc(s.begin(), s.end());
        auto f = [&] (string s) {
            for (auto &c : s) {
                if (!sc.count(c)) return false;
            }
            return true;
        };
        int ans = 0;
        for (auto &t : a) ans += f(t);
        return ans;
    }
};