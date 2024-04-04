class Solution {
public:
    int maxDepth(string s) {
        int cur = 0, ans = 0;
        for (auto c : s) {
            if (c=='(') cur++;
            if (c==')') cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};