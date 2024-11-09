using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vi>;
// using vm = vector<mint>;
// using vvm = vector<vm>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    long long minEnd(int _n, int _x) {
        ll n = _n, x = _x;
        vi a(60);
        for (ll i=0; i<30; i++) {
            if (x>>i&1) a[i] = 1;
        }
        vi b;
        n--;
        for (ll i=0; i<30; i++) {
            if (n>>i&1) b.push_back(1);
            else b.push_back(0);
        }
        int m = b.size();
        for (int i=0, j=0; i<60; i++) {
            if (a[i]) continue;
            if (j < m) a[i] = b[j++];
        }
        ll ans = 0;
        for (int i=0; i<60; i++) {
            if (a[i]) ans += (1ll<<i);
        }
        return ans;

        
    }
};