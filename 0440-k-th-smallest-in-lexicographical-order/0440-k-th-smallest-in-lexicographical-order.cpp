class Solution {
public:
    int findKthNumber(int n, int k) {
        string s = to_string(n);
        int m = s.size();
        if (m == 1) return k;


        string ans;
        bool tight = true;
        function<void(int)> f = [&] (int i) {
            if (i == m || k == 0) return;
            int cum = 0;
            for (int j=0; j<=9; j++) {
                if (i+j==0) continue;
                int t = 0, p = 1;
                for (int l=0; i+l+1 <= m; l++) {
                    if (i+l+1 == m) {
                        string z = ans;
                        z += '0' + j;
                        int len = l;
                        while (len--) z += '0';
                        if (stoi(z) > n) continue;
                    }
                    if (tight && (j == s[i]-'0') && (i+l+1==m)) {
                        auto sub = s.substr(i+1,l);
                        if (sub.empty()) t += 1;
                        else t += stoi(sub)+1;
                    }
                    else t += p;
                    p *= 10;
                }
                if (cum + t >= k) {
                    k -= cum+1;
                    ans += '0' + j;
                    if (j != s[i]-'0') tight = false;
                    f(i+1);
                    break;
                }
                else cum += t;
            }
        };
        f(0);
        int ret = stoi(ans);
        return ret;
    }
};