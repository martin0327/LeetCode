class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int j = 0;
        for (auto c : s) {
            if (j==m) break;
        if (c==t[j] || 'a'+(((c-'a')+1)%26)==t[j]) j++;
        }
        return j==m;
    }
};