using ll = long long;
using vi = vector<ll>;
const ll inf = 2e18;

struct segtree {
    ll n, sz=0;
    vi a;

    segtree(int n) {
        this->n = n;
        while ((1 << sz) < n) sz++;
        sz = (1 << sz);
        a = vi(2*sz, e());
    }

    ll e() {return -inf;}
    ll op(ll x, ll y) {return max(x,y);}
    void update(int p) {a[p] = op(a[2*p],a[2*p+1]);}

    void set(int p, ll x) {
        p += sz;
        a[p] = x;
        while (p>>=1) update(p);
    }

    ll prod(int l, int r) {
        l += sz, r += sz;
        ll lp = e(), rp = e();
        while (l < r) {
            if (l&1) lp = op(lp, a[l++]);
            if (r&1) rp = op(a[--r], rp);
            l >>= 1, r >>= 1;
        }
        return op(lp,rp);
    }

    ll get(int p) {return a[p+sz];}
    
    ll all_prod() {return a[1];}
};

class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        vi pre(n+1);
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + a[i];
        }
        map<ll,ll> comp;
        for (auto x : pre) {
            comp[x];
            comp[x-k];
        }
        ll sz = 0;
        for (auto &[k,v] : comp) {
            v = sz++;
        }
        segtree seg(sz);
        ll ans = inf;
        
        for (int i=0; i<=n; i++) {
            ll x = pre[i];
            ll t = comp[x-k];
            ll j = seg.prod(0,t+1);
            if (j != -inf) ans = min(ans, i-j);
            seg.set(comp[x], i);
        }
        if (ans == inf) ans = -1;
        return ans;        
    }
};