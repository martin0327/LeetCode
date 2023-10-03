class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        vector<int> c(101);
        int ans = 0;
        for (auto x : a) {
            ans += c[x];
            c[x]++;
        }
        return ans;
    }
};