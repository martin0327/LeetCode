using vi = vector<int>;
class Solution {
public:
    int maxRepOpt1(string t) {
        int n = t.size();
        t = " " + t;
        int ans = 0;
        for (int x=0; x<26; x++) {
            vi pre(n+1), suf(n+2);
            int tot = 0;
            for (int i=1; i<=n; i++) {
                if (t[i]-'a' == x) {
                    pre[i] = pre[i-1] + 1;
                    tot++;
                }
            }
            for (int i=n; i>=1; i--) {
                if (t[i]-'a' == x) {
                    suf[i] = suf[i+1] + 1;
                }
            }
            for (int i=1; i<=n; i++) {
                int y = pre[i-1] + suf[i+1];
                if (y < tot) ans = max(ans, y+1);
                else ans = max(ans, y);
                ans = max(ans, pre[i]);
            }
        }
        return ans;
    }
};