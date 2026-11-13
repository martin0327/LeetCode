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
    string mostCommonWord(string pr, vector<string>& ban) {
        string s;
        auto f = [&] (char x) {
            if ('a' <= x && x <= 'z') return false;
            if ('A' <= x && x <= 'Z') return false;
            return true;
        };
        for (auto c : pr) {
            if (f(c)) s += ' ';
            else s += c;
        }
        auto a = split_str(s);
        map<string,int> mp;
        for (auto &t : a) {
            for (auto &ch : t) {
                if ('A' <= ch && ch <= 'Z') {
                    ch += 'a' - 'A';
                }
            }
            mp[t]++;
        }
        int mx = 0;
        set<string> ss(ban.begin(), ban.end());
        ss.insert("");
        for (auto &[k,v] : mp) {
            if (ss.count(k)) continue;
            mx = max(mx, v);
        }
        string ans;
        for (auto &[k,v] : mp) {
            if (ss.count(k)) continue;
            if (v == mx) ans = k;
        }
        return ans;
    }
};
