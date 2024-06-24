class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<int> b(n+1);
        for (int i=0; i<n; i++) {
            if (i > 0) a[i] ^= (b[i] ^= b[i-1]);
            if (i+k-1<n) {
                if (!a[i]) {
                    b[i] ^= 1;
                    b[i+k] ^= 1;
                    ans++;
                }
            }
            else if (!a[i]) return -1;
        }
        return ans;
    }
};