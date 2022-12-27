using vc = vector<char>;
using vvc = vector<vc>;
class Solution {
public:
    string convert(string s, int k) {
        if (k==1) return s;
        int n = s.size();
        vvc a(k, vc(n));
        int i = 0, j = 0;
        for (auto c : s) {
            a[i][j] = c;
            if (j % (k-1) || i == k-1) {
                i--; j++;
            }
            else i++;
        }
        string ans;
        for (int i=0; i<k; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j]) ans += a[i][j];
            }
        }
        return ans;
    }
};    