class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& a, string t) {
        int n = t.size();
        vector<string> ret;
        for (auto s : a) {
            unordered_map<char,char> mp;
            unordered_set<char> check;
            string temp;
            for (int i=0; i<n; i++) {
                if (mp.count(s[i])) {
                    if (mp[s[i]] == t[i]) temp += t[i];
                } 
                else {
                    if (check.count(t[i])) continue;
                    check.insert(t[i]);
                    mp[s[i]] = t[i];
                    temp += t[i];
                }
            }
            if (temp==t) ret.push_back(s);
        }
        return ret;
    }
};