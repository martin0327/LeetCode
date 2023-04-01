class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        using vi = vector<int>;
        vi c(26);
        for (int i=0; i<26; i++) c[i] = i+1;        
        for (int i=0; i<chars.size(); i++) {
            c[chars[i]-'a'] = vals[i];
        }
        int n = s.size();
        vi a(n);
        for (int i=0; i<n; i++) {
            a[i] = c[s[i]-'a'];
        }
        int ans = 0;
        int cur = -1e9;
        for (auto x : a) {
            cur = max(cur + x, x);
            ans = max(ans, cur);
        }
        return ans;
    }
};