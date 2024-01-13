class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26);
        for (auto c : s) cnt[c-'a']++;
        for (auto c : t) cnt[c-'a']--;
        int ans = 0;
        for (auto x : cnt) ans += abs(x);
        ans /= 2; 
        return ans;
    }
};