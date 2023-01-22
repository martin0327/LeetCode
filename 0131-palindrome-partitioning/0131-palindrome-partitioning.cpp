using vs = vector<string>;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size()-1;
        vector<vs> ret;
        for (int mask=0; mask<1<<n; mask++) {
            vs a = {string(1,s[0])};
            for (int i=0; i<n; i++) {
                if (mask>>i&1) a.push_back(string(1,s[i+1]));
                else a.back().push_back(s[i+1]);
            }
            bool ok = true;
            for (auto x : a) {
                string y = x;
                reverse(y.begin(), y.end());
                ok &= (x==y);
            }
            if (ok) ret.push_back(a);
        }
        return ret;
    }
};