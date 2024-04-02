class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> dic1;
        map<char, char> dic2;
        bool ret = true;
        for (int i=0; i<n; i++) {
            if (dic1.count(s[i]) || dic2.count(t[i])) {
                if (dic1[s[i]] != t[i]) ret = false;
                if (dic2[t[i]] != s[i]) ret = false;
            }
            else {
                dic1[s[i]] = t[i];
                dic2[t[i]] = s[i];
            }
        }
        return ret;
    }
};