class Solution {
public:
    int minPenalty(int pr, vector<int>& a, vector<int>& b) {
        int mx = *max_element(a.begin(), a.end());
        int ans = 0;
        for (int x : b) {
            x %= pr;
            if (x >= mx) {
                ans = max(ans, pr - x);
            }
        }
        return ans;
    }
};