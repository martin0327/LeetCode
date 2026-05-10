class Solution {
public:
    string addStrings(string x, string y) {
        int n = x.size(), m = y.size();
        int sz = max(n,m) + 2;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        vector<short> a(sz), b(sz);
        for (int i=0; i<n; i++) a[i] = x[i] - '0';
        for (int i=0; i<m; i++) b[i] = y[i] - '0';
        vector<short> c(sz);
        for (int i=0; i<sz; i++) {
            if (i > 0) {
                c[i] += c[i-1] / 10;
                c[i-1] %= 10;
            }
            c[i] += a[i] + b[i];
        }
        while (c.size() && c.back() == 0) c.pop_back();
        string ans;
        while (c.size()) {
            ans += c.back() + '0';
            c.pop_back();
        }
        if (ans.empty()) ans = "0";
        return ans;
    }
};