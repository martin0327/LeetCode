class Solution {
public:
    string longestWord(vector<string>& a) {
        sort(a.begin(), a.end());
        set<string> ss;
        for (auto &s : a) {
            if (s.size() == 1) ss.insert(s);
            else {
                auto t = s.substr(0,s.size()-1);
                if (ss.count(t)) ss.insert(s);
            }
        }
        int mx = 0;
        for (auto &s : ss) {
            int sz = s.size();
            mx = max(mx, sz);
        }
        if (mx == 0) return "";
        vector<string> b;
        for (auto &s : ss) {
            int sz = s.size();
            if (mx == sz) b.push_back(s);
        }
        auto ans = *min_element(b.begin(), b.end());
        return ans;
    }
};