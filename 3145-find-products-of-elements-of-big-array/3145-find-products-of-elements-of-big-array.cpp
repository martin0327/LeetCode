using ll = long long;
using vi = vector<ll>;

template<typename T>
ll popcount(T x) {return __builtin_popcountll(x);}

ll pow_mod(ll x, ll n, ll m) {
    if (m == 1) return 0;
    ll r = 1;
    ll y = x % m;
    while (n) {
        if (n & 1) r = (r * y) % m;
        y = (y * y) % m;
        n >>= 1;
    }
    return r;
}

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<long long>>& qr) {
        function<ll(ll)> f = [&] (ll x) {
            if (x <= 1) return 0ll;
            if (x&1) return f(x-1) + popcount(x-1);
            else return 2*f(x/2) + x/2;
        };
        
        function<ll(ll)> g = [&] (ll x) {
            if (x <= 1) return 0ll;
            if (x&1) {
                ll ret = 0, y = x-1;
                for (ll i=0; i<60; i++) {
                    if (y>>i&1) ret += i;
                }
                return ret + g(x-1);
            }
            else return 2*(g(x/2) + f(x/2)); 
        };

        auto h = [&] (ll x) {
            ll lo = 1, hi = x+1, y = -1;
            while (lo <= hi) {
                ll mid = (lo+hi) / 2;
                if (f(mid) <= x) {
                    y = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            ll ret = g(y), rem = x - f(y);
            for (ll i=0; i<60; i++) {
                if (rem == 0) break;
                if (y>>i&1) {
                    ret += i;
                    rem--;
                }
            }
            return ret;
        };

        vector<int> ans;
        for (auto v : qr) {
            ll lo = v[0], hi = v[1], mod = v[2];
            ll s = h(hi+1) - h(lo);
            ans.push_back(pow_mod(2,s,mod));
        }
        return ans;
    }
};