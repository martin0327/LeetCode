class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size(), ans = 0;
        for (int i=1; i<n; i++) {
            if (abs(s[i]-s[i-1]) <= 1) {
                int x = s[i-1] - 'a';
                int y = (i+1<n) ? (s[i+1]-'a') : x;
                int z = -1;
                for (int j=0; j<26; j++) {
                    if (abs(j-x) > 1 && abs(j-y) > 1) {
                        z = j;
                        break;
                    }
                }
                s[i] = 'a' + z;
                ans++;
            }
        }
        return ans;
    }
};