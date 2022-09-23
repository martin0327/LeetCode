const int mod = 1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        int prod = 1;
        int ans = 0;
        for (int x=n; x>0; x--) {
            int d = 32 - __builtin_clz(x);
            for (int i=0; i<d; i++) {
                if ((x>>i)&1) ans = (ans+prod)%mod;
                prod = (2*prod)%mod;
            }
        }
        return ans;
    }
};