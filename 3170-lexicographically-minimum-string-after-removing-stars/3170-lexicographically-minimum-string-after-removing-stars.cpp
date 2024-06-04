using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vvi a(26);
        vi c(n);
        for (int i=0; i<n; i++) {
            if (s[i] == '*') {
                c[i] = 1;
                for (int j=0; j<26; j++) {
                    if (a[j].size()) {
                        c[a[j].back()] = 1;
                        a[j].pop_back();
                        break;
                    }
                }
            }
            else {
                a[s[i]-'a'].push_back(i);
            }
        }
        string ans;
        for (int i=0; i<n; i++) if (!c[i]) ans += s[i];
        return ans;
        
    }
};