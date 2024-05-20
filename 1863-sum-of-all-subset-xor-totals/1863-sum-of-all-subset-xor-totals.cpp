class Solution {
public:
    int subsetXORSum(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int m=0; m<(1<<n); m++) {
            int x = 0;
            for (int i=0; i<n; i++) {
                if (m>>i&1) x ^= a[i];
            }
            ans += x;
        }
        return ans;
    }
};