class Solution {
public:
    int largestCombination(vector<int>& a) {
        vector<int> cnt(30);
        for (auto x : a) {
            for (int i=0; i<30; i++) {
                if ((x>>i)&1) cnt[i]++;
            }
        }
        int ans = 0;
        for (auto x : cnt) ans = max(ans,x);
        return ans;
    }
};