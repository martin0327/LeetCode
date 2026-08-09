int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

ll f(ll x) { return x*(x+1)/2; }

struct S {
    ll cnt, len, tot, left, right;
};

S op(S x, S y) {
    S ret;
    ll cnt = x.cnt + y.cnt;
    ll len = x.len + y.len;
    if (cnt == 0) {
        ret = {cnt,len,0,0,0};
    }
    else if (x.cnt == 0) {
        ll tot = y.tot;
        ll left = x.len + y.left;
        ll right = y.right;
        ret = {cnt,len,tot,left,right};
    }
    else if (y.cnt == 0) {
        ll tot = x.tot;
        ll left = x.left;
        ll right = x.right + y.len;
        ret = {cnt,len,tot,left,right};
    }
    else {
        ll tot = x.tot + y.tot + f(x.right+y.left+2);
        ll left = x.left;
        ll right = y.right;
        ret = {cnt,len,tot,left,right};
    }
    return ret;
}

S e() { S ret = {0,0,0,0,0}; return ret; }

class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& aa, vector<vector<int>>& qr) {
        vi a(aa.begin(), aa.end());
        ll n = a.size();
        vi b(n);
        set<ll> s;
        for (int i=1; i+1<n; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                b[i] = 1;
                s.insert(i);
            }
        }
        vector<S> init(n);
        for (int i=0; i<n; i++) {
            if (b[i]) init[i] = {1,1,0,0,0};
            else init[i] = {0,1,0,0,0};
        }
        segtree<S,op,e> seg(init);
        vector<ll> ans;
        for (auto &v : qr) {
            ll t = v[0];
            if (t == 1) {
                ll l = v[1], r = v[2];
                auto res = seg.prod(l,r+1);
                if (res.cnt == 0) {
                    ans.push_back(0);
                }
                else {
                    auto it1 = s.lower_bound(l);
                    auto it2 = s.upper_bound(r);
                    ll tot = res.tot - res.cnt;
                    if (it1 != s.end()) {
                        tot += f((*it1)-l+1);
                    }
                    if (it2 != s.begin()) {
                        it2--;
                        tot += f(r-(*it2)+1);
                    }
                    ans.push_back(f(r-l+1) - tot);
                }
            }
            else {
                ll idx = v[1], val = v[2];
                a[idx] = val;
                for (int i=idx-1; i<=idx+1; i++) {
                    if (i<0 || i>=n) continue;
                    if (i>0 && i+1<n && a[i]>a[i-1] && a[i]>a[i+1]) {
                        seg.set(i, {1,1,0,0,0});
                        s.insert(i);
                    }
                    else {
                        seg.set(i,{0,1,0,0,0});
                        if (s.count(i)) s.erase(i);
                    }
                }
            }
        }
        return ans;
    }
};