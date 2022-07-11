class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;
        int x = 0;
        int y = 1;
        for (int i=0; i<n-1; i++) {
            int temp = x+y;
            x = y;
            y = temp;
        }
        return y;
    }
};