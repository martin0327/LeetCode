#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

struct segtree {
    int n, sz=0;
    vi a;

    segtree(int n) {
        while ((1<<sz) < n) sz++;
        sz = (1<<sz);
        a = vi(2*sz, e());
    }

    ll e() {return 0;}
    ll op(ll x, ll y) {return x+y;}
    void update(int p) {a[p] = op(a[2*p],a[2*p+1]);}

    void set(int p, ll x) {
        p += sz;
        a[p] = x;
        while (p>>=1) update(p);
    }

    ll prod(int l, int r) {
        if (l>r) return e();
        l += sz, r += sz;
        ll res = e();
        while (l < r) {
            if (l&1) res = op(res, a[l++]);
            if (r&1) res = op(res, a[--r]);
            l >>= 1, r >>= 1;
        }
        return res;
    }

    ll get(int p) {return a[p+sz];}
};

ll mod_pow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp&1) {
            res *= base;
            res %= mod;
        }
        base = (base*base)%mod;
        exp >>= 1;
    }
    return res;
}

class Solution {
public:
    int numSubseq(vector<int>& a, int t) {
        ll sz = 1e6;
        segtree seg(sz+1);
        for (auto x : a) seg.set(x,seg.get(x)+1);
        ll ans = 0;
        for (ll x=1; 2*x<=t; x++) {
            if (seg.get(x) > 0) {
                ll y = mod_pow(2,seg.get(x))+mod-1;
                y %= mod;
                ll z = mod_pow(2,seg.prod(x+1,t-x+1));
                ans += y*z;
                ans %= mod;
            }

        }
        return ans;
    }
};