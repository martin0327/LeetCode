const int inf = 1e9;

class Solution {
public:
    int firstUniqChar(string s) {
        int idx[26];
        memset(idx, -1, sizeof(int) * 26);
        for (int i=0; i<s.size(); i++) {
            int x = s[i] - 'a';
            if (idx[x] == -1) idx[x] = i;
            else if (idx[x] != -2) idx[x] = -2;
        }
        int ans = inf;
        for (int i=0; i<26; i++) {
            if (idx[i] >= 0) ans = min(ans, idx[i]);
        }
        if (ans==inf) ans = -1;
        return ans;
    }
};