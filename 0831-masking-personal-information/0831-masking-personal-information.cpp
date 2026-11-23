vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}

class Solution {
public:
    string maskPII(string s) {
        auto a = split_str(s, '@');
        auto to_lower = [&] (string s) {
            for (auto &ch : s) {
                if ('A' <= ch && ch <= 'Z') {
                    ch += 'a' - 'A';
                }
            }
            return s;
        };
        if (a.size() == 2) {
            string ans;
            for (int i=0; i<2; i++) {
                a[i] = to_lower(a[i]);
                if (i == 0) {
                    ans += a[i].front();
                    ans += "*****";
                    ans += a[i].back();
                }
                else {
                    ans += '@';
                    ans += a[i];
                }
            }
            return ans;
        }
        string t;
        for (auto &ch : s) {
            if ('0' <= ch && ch <= '9') {
                t += ch;
            }
        }
        int sz = t.size(), ex = sz - 10;
        string ans = "-" + t.substr(sz-4,4);
        sz -= 4;
        while (sz > 0) {
            int d = min(sz,3);
            ans = string(d, '*') + ans;
            sz -= d;
            if (sz > 0) ans = "-" + ans;
        }
        if (ex > 0) ans = "+" + ans;
        return ans;
    }
};