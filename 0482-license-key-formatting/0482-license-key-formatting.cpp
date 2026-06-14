class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;
        for (auto &c : s) {
            if ('a' <= c && c <= 'z') c += 'A' - 'a';
            if (c == '-') continue;
            t += c;
        }
        int n = t.size(), r = n % k;
        s.clear();
        for (int i=0; i<n; i++) {
            if ((i % k == r) && (i > 0)) s += '-';
            s += t[i];
        }
        return s;
    }
};