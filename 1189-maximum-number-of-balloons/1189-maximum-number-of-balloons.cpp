string t = "balloon";
map<char,int> mp;
class Solution {
public:
    int maxNumberOfBalloons(string s) {
        if (mp.empty()) {
            for (auto &ch : t) {
                mp[ch]++;
            }
        }
        map<char,int> cnt;
        for (auto &ch : s) {
            if (mp.count(ch)) {
                cnt[ch]++;
            }
        }
        int ans = 2e9;
        for (auto &[k,v] : mp) {
            ans = min(ans, cnt[k] / v);
        }
        return ans;
    }
};