class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = 32;
        vector<long long> b(n);
        for (auto x : a) {
            for (int i=0; i<n; i++) {
                if (x>>i&1) b[i] = (b[i]+1)%3;
            }
        }
        long long ans = 0;
        for (int i=0; i<n; i++) {
            if (b[i]) ans |= (1ll<<i);
        }
        return ans;
    }
};