class Solution {
public:
    int minOperations(int k) {
        int ans = k - 1;
        for (int i=1; i<=k/2; i++) {
            int x = 1 + i;
            int q = (k + (x-1)) / x;
            ans = min(ans, q-1+i);
        }
        return ans;
    }
};