class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cnt(26);
        for (auto s : words2) {
            vector<int> temp(26);
            for (auto c : s) {
                int x = c - 'a';
                temp[x]++;
            }
            for (int i=0; i<26; i++) {
                cnt[i] = max(cnt[i], temp[i]);
            }
        }
        vector<string> ret;
        for (auto s : words1) {
            vector<int> temp(26);
            for (auto c : s) {
                int x = c - 'a';
                temp[x]++;
            }
            bool ok = true;
            for (int i=0; i<26; i++) {
                if (cnt[i] > temp[i]) ok = false;
            }
            if (ok) ret.push_back(s);
        }
        return ret;
    }
};