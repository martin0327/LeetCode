vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}
using vs = vector<string>;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& a) {
        vs ans;
        map<string,int> mp;
        for (auto &s : a) {
            auto b = split_str(s);
            auto cnt = stoi(b[0]);
            auto c = split_str(b[1],'.');
            reverse(c.begin(), c.end());
            string cur;
            for (auto t : c) {
                cur = t + cur;
                mp[cur] += cnt;
                cur = "." + cur;
            }
        }
        for (auto [k,v] : mp) {
            ans.push_back(to_string(v));
            ans.back() += " " + k;
        }
        return ans;
    }
};