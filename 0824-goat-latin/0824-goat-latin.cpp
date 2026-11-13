
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
    string toGoatLatin(string s) {
        set<char> vowel;
        {
            string t = "aeiouAEIOU";
            vowel = set<char>(t.begin(), t.end());
        }
        auto a = split_str(s);
        string ans;
        int cnt = 1;
        for (auto &t : a) {
            if (vowel.count(t[0])) {
                t += "ma";
                t += string(cnt,'a');
                ans += t;
                ans += ' ';
            }
            else {
                t += t[0];
                t.erase(t.begin());
                t += "ma";
                t += string(cnt,'a');
                ans += t;
                ans += ' ';
            }
            cnt++;
        }
        ans.pop_back();
        return ans;
    }
};