using ll = long long;
const ll mod = 1e9+7;

class Solution {
public:
    int countVowelPermutation(int n) {
        ll a,e,i,o,u;
        a=e=i=o=u=1;
        while (--n) {
            int aa,ee,ii,oo,uu;
            aa = e;
            ee = (a+i)%mod;
            ii = (a+e+o+u)%mod;
            oo = (i+u)%mod;
            uu = a;
            
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        
        ll ans = (a+e+i+o+u)%mod;
        return ans;
    }
};