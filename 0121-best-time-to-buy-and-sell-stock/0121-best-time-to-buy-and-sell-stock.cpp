class Solution {
public:
    int maxProfit(vector<int>& a) {
        int prv = 1e9, ans = 0;
        for (auto x : a) {
            ans = max(ans, x - prv);
            prv = min(prv, x);
        }
        return ans;
    }
};