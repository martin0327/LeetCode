class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        map<vector<int>, vector<string>> mp;
        for (auto s : a) {
            vector<int> cnt(26);
            for (auto c : s) cnt[c-'a']++;
            mp[cnt].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto &[k,v] : mp) ret.push_back(v);
        return ret;
    }
};