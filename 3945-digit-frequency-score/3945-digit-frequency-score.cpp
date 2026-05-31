class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        for (auto ch : to_string(n)) {
            ans += ch - '0';
        }
        return ans;
    }
};