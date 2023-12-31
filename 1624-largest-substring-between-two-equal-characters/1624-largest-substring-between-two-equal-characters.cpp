class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        int n = s.size();
        vector<int> pr(26,-1);
        for (int i=0; i<n; i++) {
            int x = s[i] - 'a';
            if (pr[x] == -1) pr[x] = i;
            else ans = max(ans, i - pr[x] - 1);
        }
        return ans;
    }
};