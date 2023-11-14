using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vi a(26);
        vvi b(26,vi(26));
        vector c(26, vvi(26, vi(26)));
        int ans = 0;
        for (auto ch : s) {
            int x = ch - 'a';
            for (int i=0; i<26; i++) {
                if (b[x][i]) c[x][i][x] = 1;
            }
            for (int i=0; i<26; i++) {
                if (a[i]) b[i][x] = 1;
            }
            a[x] = 1;
        }
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                for (int k=0; k<26; k++) {
                    ans += c[i][j][k];
                }
            }
        }
        return ans;
    }
};