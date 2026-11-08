using vs = vector<string>;
using vvs = vector<vs>;
const vs b = {"",""};
class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s, string t) {
        int n = s.size();
        vvs a = {b};
        for (int i=0; i<n; i++) {
            if (s[i] == t[i]) a.push_back(b);
            else {
                a.back()[0] += s[i];
                a.back()[1] += t[i];
            }
        }
        vvs ans;
        for (auto &v : a) {
            if (v == b) continue;
            else ans.push_back(v);
        }
        return ans;
    }
};