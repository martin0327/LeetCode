class Solution {
public:
    bool checkPerfectNumber(int x) {
        if (x == 1) return false;
        int s = 1;
        for (int i=2; i*i<=x; i++) {
            if (x % i == 0) {
                s += i;
                if (i != x/i) s += x/i;
            }
        }
        return x == s;
    }
};