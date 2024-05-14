using vi = vector<int>;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vi a(26), b(26);
        int n = s.size();
        for (int i=0; i<n; i++) {
            a[s[i]-'a'] = i;
            b[t[i]-'a'] = i;
        }
        int ans = 0;
        for (int i=0; i<26; i++) {
            ans += abs(a[i]-b[i]);
        }
        return ans;
    }
};