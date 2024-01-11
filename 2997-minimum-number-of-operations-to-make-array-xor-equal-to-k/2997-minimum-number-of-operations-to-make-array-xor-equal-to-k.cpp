class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        for (auto x : a) k ^= x;
        return __builtin_popcount(k);
    }
};