int f(int n) {
    while((n & (n-1)) != 0){
        n = n & (n-1);
    }
    return n;
}

class Solution {
public:
    int smallestNumber(int n) {
        return (f(n)<<1) - 1;
    }
};