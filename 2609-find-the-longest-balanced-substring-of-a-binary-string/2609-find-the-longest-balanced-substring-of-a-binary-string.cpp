using vi = vector<int>;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        s = "0" + s;
        vi pre(n+1), suf(n+2);
        for (int i=1; i<=n; i++) {
            if (s[i]=='0') pre[i] = pre[i-1] + 1;
            else pre[i] = 0;
        }
        for (int i=n; i>=1; i--) {
            if (s[i]=='1') suf[i] = suf[i+1] + 1;
            else suf[i] = 0;
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            int x = pre[i];
            int y = suf[i+1];
            ans = max(ans, 2*min(x,y));
        }
        return ans;
    }
};