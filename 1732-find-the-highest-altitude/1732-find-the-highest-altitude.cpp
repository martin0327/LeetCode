class Solution {
public:
    int largestAltitude(vector<int>& a) {
        int cur = 0, ans = 0;
        for (auto x : a) {
            cur += x;
            ans = max(ans, cur);
        }
        return ans;
    }
};