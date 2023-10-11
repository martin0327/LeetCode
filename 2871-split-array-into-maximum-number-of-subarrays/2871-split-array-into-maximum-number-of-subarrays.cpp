class Solution {
public:
    int maxSubarrays(vector<int>& a) {
        int n = a.size();
        int s = a[0];
        for (auto x : a) s &= x;
        if (s>0) return 1;

        int cur = ~0, ans = 0;
        for (auto x : a) {
            cur &= x;
            if (cur==0) {
                ans++;
                cur = ~0;
            }
        }
        return ans;
    }
};
