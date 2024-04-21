using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int numberOfSpecialChars(string s) {
        vvi a(26), b(26);
        int n = s.size();
        for (int i=0; i<n; i++) {
            char c = s[i];
            int x = c - 'a';
            int y = c - 'A';
            auto f = [&] (int x) {
                return 0 <= x && x < 26;
            };
            if (f(x)) a[x].push_back(i);
            if (f(y)) b[y].push_back(i);
        }
        int ans = 0;
        for (int i=0; i<26; i++) {
            if (a[i].size() && b[i].size()) {
                if (a[i].back() < b[i].front()) ans++;
            }
        }
        return ans;
    }
};