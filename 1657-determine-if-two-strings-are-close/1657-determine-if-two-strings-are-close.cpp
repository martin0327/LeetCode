class Solution {
public:
    bool closeStrings(string s, string t) {
        map<char,int> mp1, mp2;
        for (auto c : s) mp1[c]++;
        for (auto c : t) mp2[c]++;
        vector<int> a,b;
        int c = 0, d = 0;
        for (auto &[k,v] : mp1) {
            a.push_back(v);
            c |= (1<<(k-'a'));
        }
        for (auto &[k,v] : mp2) {
            b.push_back(v);
            d |= (1<<(k-'a'));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b && c==d;
    }
};