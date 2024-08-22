class Solution {
public:
    int findComplement(int x) {
        int k = 32 - __builtin_clz(x);
        return ((1ll<<k)-1) ^ x;
    }
};