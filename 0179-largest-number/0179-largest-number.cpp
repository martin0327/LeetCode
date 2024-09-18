class Solution {
public:
    string largestNumber(vector<int>& a) {
        vector<string> b;
        for (auto &x : a) b.push_back(to_string(x));
        int n = b.size();
        sort(b.begin(), b.end(), [&] (string &s, string &t) {
            string st = s + t, ts = t + s;
            return st > ts;
        });
        string ans;
        for (auto s : b) ans += s;
        set<char> sc(ans.begin(), ans.end());
        if (sc.size() == 1 && sc.count('0')) return "0";
        return ans;
    }
};