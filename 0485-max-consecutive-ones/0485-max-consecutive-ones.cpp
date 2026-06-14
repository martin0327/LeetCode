class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int ans = 0, cur = 0;
        for (auto x : a) {
            if (x) cur++;
            else cur = 0;
            ans = max(ans, cur);
        }
        return ans;
    }
};