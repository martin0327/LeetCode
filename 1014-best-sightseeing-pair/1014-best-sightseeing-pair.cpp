class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int ans = 0, cur = -1e9;
        for (auto &x : a) {
            ans = max(ans, x+(--cur));
            cur = max(cur, x);
        }
        return ans;
    }
};