class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int z = 0, j = -1;
        for (auto x : a) z ^= x;
        for (int i=0; i<32; i++) {
            if (z>>i&1) j = i;
        }
        vector<int> ans(2);
        for (auto y : a) ans[y>>j&1] ^= y;
        return ans;
    }
};