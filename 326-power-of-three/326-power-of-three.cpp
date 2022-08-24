const int c = 1162261467;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return (c % n == 0);
    }
};