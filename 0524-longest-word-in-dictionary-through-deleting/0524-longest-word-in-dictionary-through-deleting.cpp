using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    string findLongestWord(string s, vector<string>& a) {
        int n = s.size(), sz = 26;
        vvi b(sz);
        for (int i=0; i<n; i++) {
            b[s[i]-'a'].push_back(i);
        }
        vector<pair<int,string>> res;
        for (auto &t : a) {
            int cur = -1;
            bool ok = true;
            for (auto ch : t) {
                auto &v = b[ch-'a'];
                auto it = upper_bound(v.begin(), v.end(), cur);
                if (it == v.end()) {
                    ok = false;
                    break;
                }
                else cur = *it;
            }
            if (ok) res.push_back({(int)t.size() * -1, t});
        }
        if (res.empty()) return "";
        auto [len,ans] = *min_element(res.begin(), res.end());
        return ans;
    }
};