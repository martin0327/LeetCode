class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> idx = {0};
        for (int i=1; i<n; i++) {
            if (groups[idx.back()] != groups[i]) idx.push_back(i);
        }
        vector<string> ret;
        for (auto i : idx) ret.push_back(words[i]);
        return ret;

    }
};