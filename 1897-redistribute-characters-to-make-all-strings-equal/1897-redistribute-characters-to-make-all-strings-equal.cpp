class Solution {
public:
    bool makeEqual(vector<string>& a) {
        int n = a.size();
        vector<int> cnt(26);
        for (auto s : a) {
            for (auto c : s) {
                int x = c - 'a';
                cnt[x]++;
            }
        }
        bool ans = true;
        for (auto c : cnt) ans &= (c % n == 0);
        return ans;
    }
};