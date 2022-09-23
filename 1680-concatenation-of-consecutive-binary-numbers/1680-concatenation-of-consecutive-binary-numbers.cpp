using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        ll prod = 1;
        ll ans = 0;
        for (int x=n; x>0; x--) {
            ans = (ans+x*prod)%mod;
            prod = (prod<<(32 - __builtin_clz(x)))%mod;            
        }
        return ans;
    }
};