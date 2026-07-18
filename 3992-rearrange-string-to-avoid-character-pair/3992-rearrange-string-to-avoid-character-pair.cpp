class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        map<char,int> mp;
        for (auto ch : s) mp[ch]++;
        string ans;
        int c1 = mp[y], c2 = mp[x];
        while (c1--) ans += y;
        for (auto [k,v] : mp) {
            if (k == x || k == y) continue;
            while (v--) ans += k;
        }
        while (c2--) ans += x;
        return ans;
    }
};