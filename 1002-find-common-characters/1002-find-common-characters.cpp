class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        vector<int> min_cnt(26, 1000);
        for (auto s : a) {
            vector<int> cnt(26);
            for (auto c : s) {
                cnt[c-'a']++;
            }
            for (int i=0; i<26; i++) {
                min_cnt[i] = min(min_cnt[i], cnt[i]);
            }
        }
        vector<string> ans;
        for (int i=0; i<26; i++) {
            int c = min_cnt[i];
            while (c--) {
                ans.push_back(string(1,'a'+i));
            }
        }
        return ans;
    }
};