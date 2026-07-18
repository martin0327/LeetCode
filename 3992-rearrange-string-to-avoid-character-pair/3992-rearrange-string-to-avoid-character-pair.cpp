class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        map<char,int> mp;
        for (auto ch : s) mp[ch]++;
        string ans;
        int cnt1 = mp[y], cnt2 = mp[x];
        while (cnt1--) ans += y;
        for (auto [k,v] : mp) {
            if (k == x || k == y) continue;
            while (v--) ans += k;
        }
        while (cnt2--) ans += x;
        return ans;
    }
};