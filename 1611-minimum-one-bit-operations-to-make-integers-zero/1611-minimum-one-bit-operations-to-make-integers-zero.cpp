class Solution {
public:
    map<int,int> dp1, dp2;
    
    int msb(int x) {
        int p = 63 - __builtin_clzll(x);
        return 1<<p;
    }

    int f(int x) {
        if (dp1.count(x)) return dp1[x];
        if (x <= 1) return dp1[x] = x;
        if (__builtin_popcount(x) == 1) return dp1[x] = 1 + g(x>>1) + f(x>>1);
        int m = msb(x);
        int y = x - m;

        if (y >= m/2) return dp1[x] = 1 + f(m/2) + f(y-(m/2));
        else {
            int mm = msb(y);
            return dp1[x] = 1 + f(y-mm) + g(m/2) - g(mm) + f(m/2);
        }
    }

    int g(int x) {
        assert((x&(x-1)) == 0);
        if (x <= 1) return x;
        return dp2[x] = g(x/2) + f(x/2) + 1;
    }

    int minimumOneBitOperations(int n) {
        return f(n);
    }
};   