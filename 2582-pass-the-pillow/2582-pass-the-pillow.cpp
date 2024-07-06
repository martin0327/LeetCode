class Solution {
public:
    int passThePillow(int n, int t) {
        int r = t % (2*(n-1));
        if (r >= n) r = 2*(n-1) - r;
        return r+1;
    }
};