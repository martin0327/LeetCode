class Solution {
public:
    int maxScoreWords(vector<string>& a, vector<char>& b, vector<int>& s) {
        int n = a.size();
        vector<int> cnt(26);
        for (auto c : b) {
            cnt[c-'a']++;
        }
        int ans = 0;
        for (int mask=0; mask < (1<<n); mask++) {
            vector<int> cur(26);
            for (int i=0; i<n; i++) {
                if ((mask>>i)&1) {
                    for (auto c : a[i]) {
                        cur[c-'a']++;
                    }
                }
            }
            bool ok = true;
            int temp = 0;
            for (int i=0; i<26; i++) {
                if (cur[i] > cnt[i]) ok = false;
                else temp += cur[i] * s[i];
            }
            if (ok) ans = max(ans, temp);
        }
        return ans;
    }
};