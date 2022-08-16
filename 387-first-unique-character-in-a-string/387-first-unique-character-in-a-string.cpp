class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> idx(26,-1);
        for (int i=0; i<s.size(); i++) {
            int x = s[i] - 'a';
            if (idx[x] == -1) idx[x] = i;
            else if (idx[x] != -2) idx[x] = -2;
        }
        int ans = 1e9;
        for (int i=0; i<26; i++) {
            if (idx[i] >= 0) ans = min(ans, idx[i]);
        }
        if (ans==1e9) ans = -1;
        return ans;
    }
};