class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> pre(n+1), suf(n+2);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + (s[i-1]=='N');
        for (int i=n; i>=1; i--) suf[i] = suf[i+1] + (s[i-1]=='Y');
        pair<int,int> ans = {1e9,1e9};
        for (int i=0; i<=n; i++) {
            int x = pre[i] + suf[i+1];
            ans = min(ans, make_pair(x,i));
        }
        return ans.second;
    }
};