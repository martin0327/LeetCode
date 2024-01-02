class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> s(a.begin(), a.end());
        int ans = 0;
        for (auto x : s) {
            if (!s.count(x-1)) { // O(1)
                int len = 1;
                for (int i=x+1; ; i++) {
                    if (!s.count(i)) break;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;            
    }
};