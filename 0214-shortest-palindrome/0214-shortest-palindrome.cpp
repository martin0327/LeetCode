int zero = 0;
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(zero, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return s;
        auto a = manacher(s);
        int m = a.size(), mx = 1;
        for (int i=0; i<m; i++) {
            int sz = a[i] / 2;
            int j = i / 2;
            if (i&1) {
                // even 
                if (sz == j+1) {
                    mx = max(mx, 2*sz);
                }
            }
            else {
                // odd
                if (sz == j+1) {
                    mx = max(mx, 2*sz-1);
                }

            }
        }
        int sz = n - mx;
        auto t = s.substr(n-sz,sz);
        reverse(t.begin(), t.end());
        string ans = t + s;
        return ans;
    }
};