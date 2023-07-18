class Solution {
public:
    int maximumBeauty(vector<int>& a, int k) {
        int n = a.size(), sz = 3e5+1;
        vector<int> b(sz+1);
        for (auto x : a) {
            b[x]++;
            b[x+2*k+1]--;
        }
        int ans = b[0];
        for (int i=1; i<=sz; i++) {
            b[i] += b[i-1];
            ans = max(ans, b[i]);
        }
        return ans;
    }
};