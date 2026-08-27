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
        auto push = [&] (int j, int t) { 
            while (t--) {
                ans += 'a' + j; 
            }
        };

        auto g = [&] (int x) {
            for (int j=x+1; j<sz; j++) {
                if (c[j] > 0) {
                    push(j,1);
                    c[j]--;
                    break;
                }
            }
            for (int j=0; j<sz; j++) {
                push(j,c[j]);
            }
        };
        for (int i=0; i<n; i++) {
            if (!f(i)) return "";
            if (i == n-1) {
                for (int j=0; j<sz; j++) {
                    if (c[j]) push(j,1);
                }
            }
            else {
                int x = tg[i] - 'a';
                if (c[x] > 0) {
                    c[x]--;
                    if (f(i+1)) {
                        push(x,1);
                    } 
                    else {
                        c[x]++;
                        g(x);
                        return ans;
                    }
                }
                else {
                    g(x);
                    return ans;
                }
            }
        }
        return ans;
    }
};