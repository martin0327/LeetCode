class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int m) {
        int n = a.size(), x = (1<<m)-1;
        vector<int> ans(n);
        for (auto y : a) x ^= y;
        for (int i=0; i<n; i++) {
            ans[i] = x;
            x ^= a[n-1-i];
        }
        return ans;        
    }
};