class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int x = 0, y = 0;
        for (int i=1; i<=n; i++) {
            x += 2*i-1;
            y += 2*i;
        }
        return gcd(x,y);
    }
};