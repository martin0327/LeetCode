class Solution {
public:
    bool closeStrings(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> cnt1(26), cnt2(26);
        for (auto c : s) cnt1[c-'a']++;
        for (auto c : t) cnt2[c-'a']++;
        vector<int> a,b;
        int c = 0, d = 0;
        for (int i=0; i<26; i++) {
            a.push_back(cnt1[i]);
            b.push_back(cnt2[i]);
            if (cnt1[i]) c |= 1<<i;
            if (cnt2[i]) d |= 1<<i;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b && c==d;
    }
};