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
    vector<string> wordBreak(string s, vector<string>& wd) {
        set<string> ss(wd.begin(), wd.end());
        int n = s.size(), m = n-1;
        vector<string> ans;
        for (int mask=0; mask<(1<<m); mask++) {
            string t;
            for (int i=0; i<n; i++) {
                t += s[i];
                if (mask>>i&1) t += " ";
            }
            auto split = split_str(t);
            bool ok = true;
            for (auto x : split) {
                if (!ss.count(x)) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(t);
        }
        return ans;
    }
};