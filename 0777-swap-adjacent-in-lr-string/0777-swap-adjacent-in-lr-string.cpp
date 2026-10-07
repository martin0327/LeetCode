using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
class Solution {
public:
    bool canTransform(string s, string t) {
        int n = s.size();
        vs st = {s,t};
        vvi a(2);
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                if (st[i][j] != 'X') {
                    a[i].push_back(j);
                }
            }
        }
        bool ans = true;
        if (a[0].size() != a[1].size()) return false;
        int sz = a[0].size();
        for (int i=0; i<sz; i++) {
            auto j1 = a[0][i], j2 = a[1][i];
            if (s[j1] != t[j2]) return false;
            if (s[j1] == 'L' && j1 < j2) return false;
            if (s[j1] == 'R' && j1 > j2) return false;
        }
        return true;
    }
};