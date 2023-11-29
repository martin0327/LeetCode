using ll = long long;
const ll mod = 1e9+7;

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        ll cnt = 0;        
        for (ll i=n-1; i>=0; i--) {
            ll x = (a>>i&1), y = (b>>i&1);
            if (x==y) {
                a |= (1ll<<i);
                b |= (1ll<<i);
            }
            else {
                if (a > b) {
                    if (x==1) {
                        a ^= (1ll<<i);
                        b ^= (1ll<<i);
                    }
                }
                else {
                    if (y==1) {
                        a ^= (1ll<<i);
                        b ^= (1ll<<i);
                    }
                }
            }
        }
        a %= mod;
        b %= mod;
        return (a*b)%mod;
    }
};