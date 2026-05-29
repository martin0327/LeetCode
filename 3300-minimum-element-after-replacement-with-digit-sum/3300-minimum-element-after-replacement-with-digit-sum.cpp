class Solution {
public:
    int minElement(vector<int>& a) {
        int ans = 1e9;
        for (auto x : a) {
            int s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            ans = min(ans, s);
        }
        return ans;
    }
};