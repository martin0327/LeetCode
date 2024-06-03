using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        for (int i=0, j=0; j<n; j++) {
            while (i<n && s[i] != t[j]) i++;
            if (i >= n) return m-j;
            else i++;
        }
        return 0;
    }
};