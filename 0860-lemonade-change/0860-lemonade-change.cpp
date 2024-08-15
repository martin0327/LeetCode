class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        vector<int> cnt(5);
        for (auto x : a) {
            x /= 5;
            if (x == 1) cnt[x]++;
            if (x == 2) {
                cnt[x]++;
                if (cnt[1] == 0) return false;
                else cnt[1] --;
            }
            if (x == 4) {
                if (cnt[2] && cnt[1]) {
                    cnt[2]--;
                    cnt[1]--;
                }
                else if (cnt[1] >= 3) cnt[1] -= 3;
                else return false;
            }
        }
        return true;
    }
};