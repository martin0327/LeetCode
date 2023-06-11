using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pii>;
using vvp = vector<vp>;

struct segtree {
    ll n, sz=0;
    vi a;

    segtree(int n) {
        this->n = n;
        while ((1 << sz) < n) sz++;
        sz = (1 << sz);
        a = vi(2*sz, e());
    }

    ll e() {return -1;}
    ll op(ll x, ll y) {return max(x,y);}
    void update(int p) {a[p] = op(a[2*p],a[2*p+1]);}

    void set(int p, ll x) {
        p += sz;
        a[p] = x;
        while (p>>=1) update(p);
    }

    ll prod(int l, int r) {
        l += sz, r += sz;
        ll res = e();
        while (l < r) {
            if (l&1) res = op(res, a[l++]);
            if (r&1) res = op(res, a[--r]);
            l >>= 1; r >>= 1;
        }
        return res;
    }

    ll get(int p) {return a[p+sz];}
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& a, vector<int>& b, vector<vector<int>>& qr) {
        ll n = a.size();

        map<ll,ll> comp;
        for (auto x : b) comp[x];
        ll q = qr.size();
        for (int i=0; i<q; i++) {
            comp[qr[i][1]];
        }
        ll sz = 0;
        for (auto &[k,v] : comp) v = sz++;
        segtree seg(sz);

        vp c(n);
        for (int i=0; i<n; i++) c[i] = {a[i],b[i]};
        sort(c.begin(), c.end());
        
        vector<tuple<ll,ll,ll>> off(q);
        for (int i=0; i<q; i++) {
            off[i] = {qr[i][0],qr[i][1],i};
        }
        sort(off.rbegin(), off.rend());        

        vector<int> ans(q);

        for (auto [x,y,idx] : off) {
            while (c.size()) {
                auto [xx,yy] = c.back();
                if (xx >= x) {
                    c.pop_back();
                    ll val = max(seg.get(comp[yy]), xx+yy);
                    seg.set(comp[yy], val);
                }
                else break;
            }
            ans[idx] = seg.prod(comp[y],sz);
        }
        return ans;
    }
};