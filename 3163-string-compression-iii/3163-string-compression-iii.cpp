class Solution {
public:
    string compressedString(string s) {
        vector<string> a;
        for (auto c : s) {
            if (a.empty() || a.back().back() != c) a.push_back(string(1,c));
            else a.back() += c;
        }
        string ans;
        for (auto t : a) {
            int m = t.size();
            int q = m / 9;
            int r = m % 9;
            while (q--) {
                ans += '9';
                ans += t[0];
            }
            if (r > 0) {
                ans += '0' + r;
                ans += t[0];
            }
        }
        return ans;        
    }
};