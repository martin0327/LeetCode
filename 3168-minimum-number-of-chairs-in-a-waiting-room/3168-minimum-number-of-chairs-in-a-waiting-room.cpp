class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0, cur = 0;
        for (auto c : s) {
            if (c=='E') cur++;
            else cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};