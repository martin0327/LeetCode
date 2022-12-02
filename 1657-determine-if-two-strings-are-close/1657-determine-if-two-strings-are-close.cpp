class Solution {
public:
    bool closeStrings(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> a(26), b(26);
        int c = 0, d = 0;
        for (auto c : s) a[c-'a']++;
        for (auto c : t) b[c-'a']++;
        for (int i=0; i<26; i++) {
            if (a[i]) c |= 1<<i;
            if (b[i]) d |= 1<<i;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b && c==d;
    }
};