using vi = vector<int>;

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        map<char,vi> mp;
        for (int i=0; i<n; i++) {
            char c = s[i];
            mp[c].push_back(i);
        }
        int ans = 0;
        for (int i=0; i<26; i++) {
            char x = 'a' + i, y = x ^ 32;
            if (mp.count(x) && mp.count(y)) {
                if (mp[x].back() < mp[y].front()) ans++;
            }
        }
        return ans;
    }
};