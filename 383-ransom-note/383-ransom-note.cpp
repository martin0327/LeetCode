class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> cnt1(26), cnt2(26);
        for (auto c : a) cnt1[c-'a']++;
        for (auto c : b) cnt2[c-'a']++;
        for (int i=0; i<26; i++) {
            if (cnt1[i]>cnt2[i]) return false;
        }
        return true;
    }
};