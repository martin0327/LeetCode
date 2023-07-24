class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        bool inv = n < 0;
        long long m = n;
        m = abs(m);
        while (m) {
            if (m&1) ret *= x;
            x = x * x;
            m >>= 1;
        }
        if (inv) ret = 1.0 / ret;
        return ret;
    }
};