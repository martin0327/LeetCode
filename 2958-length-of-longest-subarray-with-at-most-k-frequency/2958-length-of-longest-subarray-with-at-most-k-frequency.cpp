using ll = long long;
using vi = vector<ll>;

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

struct segtree {
    ll n, sz=0;
    vi a;

    segtree(int n) {
        this->n = n;
        while ((1 << sz) < n) sz++;
        sz = (1 << sz);
        a = vi(2*sz, e());
    }

    ll e() {return 0;}
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
    
    ll all_prod() {return a[1];}

    ll get(int p) {return a[p+sz];}
};

class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        ll n = a.size();
        map<ll,ll> cc;
        ll sz = 0;
        {
            auto b = get_unique(a);
            sz = b.size();
            for (int i=0; i<sz; i++) cc[b[i]] = i;
        }
        for (auto &x : a) x = cc[x];
        
        segtree seg(sz);
        ll i = 0, j = 0, ans = 0;
        while (i<n) {
            if (seg.all_prod() <= k && j < n) {
                seg.set(a[j],seg.get(a[j++])+1);
            }
            else {
                seg.set(a[i],seg.get(a[i++])-1);
            }
            if (seg.all_prod() <= k) ans = max(ans, j-i);
        }
        return ans;
    }
}; 