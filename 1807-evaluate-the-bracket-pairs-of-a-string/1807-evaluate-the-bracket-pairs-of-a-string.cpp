class Solution {
public:
    string evaluate(string s, vector<vector<string>>& b) {
        map<string,string> mp;
        for (auto &v : b) {
            mp[v[0]] = v[1];
        }
        vector<string> a = {""};
        for (auto ch : s) {
            if (ch == '(') {
                a.push_back("");
                a.back() += ch;
            }
            else if (ch == ')') {
                a.back() += ch;
                a.push_back("");
            }
            else {
                a.back() += ch;
            }
        }
        string ans;
        for (auto t : a) {
            if (t.empty()) continue;
            if (t.back() == ')') {
                t.pop_back();
                t.erase(t.begin());
                if (mp.count(t)) ans += mp[t];
                else ans += '?';
            }
            else ans += t;
        }
        return ans;
    }
};