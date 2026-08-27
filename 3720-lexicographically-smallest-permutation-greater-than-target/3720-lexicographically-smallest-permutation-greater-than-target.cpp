using vi = vector<int>;
class Solution {
public:
    string lexGreaterPermutation(string s, string tg) {
        int n = s.size(), sz = 26;
        vi c(26);
        for (auto x : s) c[x-'a']++;
        auto f = [&] (int i) {
            string t;
            for (int j=25; j>=0; j--) {
                int x = c[j];
                while (x--) t += 'a' + j;
            }
            return t > tg.substr(i,tg.size()-i);
        };
        string ans;
        auto g = [&] (int x) {
            for (int j=x+1; j<sz; j++) {
                if (c[j] > 0) {
                    ans += 'a' + j;
                    c[j]--;
                    break;
                }
            }
            for (int j=0; j<sz; j++) {
                int x = c[j];
                while (x--) ans += 'a' + j;
            }
        };
        for (int i=0; i<n; i++) {
            if (!f(i)) return "";
            if (i == n-1) {
                for (int j=0; j<sz; j++) {
                    if (c[j]) ans += 'a' + j;
                }
            }
            else {
                int x = tg[i] - 'a';
                if (c[x] > 0) {
                    c[x]--;
                    if (f(i+1)) {
                        ans += 'a' + x;
                    } 
                    else {
                        c[x]++;
                        g(x);
                        return ans;
                    }
                }
                else {
                    g(x);
                    // for (int j=x+1; j<sz; j++) {
                    //     if (c[j] > 0) {
                    //         ans += 'a' + j;
                    //         c[j]--;
                    //         break;
                    //     }
                    // }
                    // for (int j=0; j<sz; j++) {
                    //     int x = c[j];
                    //     while (x--) ans += 'a' + j;
                    // }
                    return ans;
                }
            }
        }
        return ans;
    }
};