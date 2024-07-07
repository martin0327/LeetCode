using vs = vector<string>;

class Solution {
public:
    vector<string> validStrings(int n) {
        vs ret;
        for (int mask=0; mask<(1<<n); mask++) {
            bool ok = true;
            for (int i=0; i+1<n; i++) {
                if (((mask>>i)&3) == 0) ok = false;
            }
            if (ok) {
                string s;
                for (int i=0; i<n; i++) {
                    if (mask>>i&1) s += '1';
                    else s += '0';
                }
                ret.push_back(s);
            }
        }
        return ret;
    }
};