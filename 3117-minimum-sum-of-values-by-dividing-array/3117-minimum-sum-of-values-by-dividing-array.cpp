using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
const ll inf = 2e18;

struct segt {
    ll n, sz=0;
    vi a;

    segt(int n) {
        this->n = n;
        while ((1 << sz) < n) sz++;
        sz = (1 << sz);
        a = vi(2*sz, e());
    }

    ll e() {return inf;}
    ll op(ll x, ll y) {return min(x,y);}
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


template<typename T,  T (*op)(T, T)>
struct sparse_table {
    ll n,m;
    vector<vector<T>> table;

    inline T merge(T x, T y) {
        return op(x, y);
    }

    sparse_table(vector<T> &a) {
        n = a.size();
        m = __lg(n) + 1;
        table.assign(m, vector<T>(n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];
        for (ll i = 1; i < m; i++) {
            for (ll j = 0; j + (1<<i) <= n; j++) {
                table[i][j] = merge(table[i-1][j], table[i-1][j + (1<<(i-1))]);
            }
        }
    }

    T query(ll l, ll r) {
        // l, r : inclusive
        assert(l<=r && 0<=l && r< n);
        ll u = __lg(r-l+1);
        return merge(table[u][l], table[u][r-(1<<u)+1]);
    }

    T query(ll l, ll r, T e) {
        // e for identity
        l = max(l,0ll);
        r = min(r,n-1);
        ll u = __lg(r-l+1);
        if (l<=r) return merge(table[u][l], table[u][r-(1<<u)+1]);
        else return e;
    }
};

template<typename T> T op_and(T x, T y) {return x & y;}
template<typename T> using and_spt = sparse_table<T,op_and>;

class Solution {
public:
    int minimumValueSum(vector<int>& aa, vector<int>& bb) {
        vi a(aa.begin(), aa.end());
        vi b(bb.begin(), bb.end());
        ll n = a.size(), m = b.size();
        a.insert(a.begin(), 0);
        b.insert(b.begin(), 0);

        and_spt<ll> spt(a);
        vector<segt> dp(m+1, segt(n+1));
        dp[0].set(0, 0);
        
        for (ll j=1; j<=m; j++) {
            for (ll i=1; i<=n; i++) {
                if ((b[j] & a[i]) != b[j]) continue;
                ll left = -1, right = -1;
                {
                    ll lo = 1, hi = i;
                    while (lo <= hi) {
                        ll mid = (lo+hi) / 2;
                        ll x = spt.query(mid,i);
                        if (x >= b[j]) {
                            left = mid;
                            hi = mid - 1;
                        }
                        else lo = mid + 1;
                    }
                }
                if (left == -1) continue;
                
                {
                    ll lo = 1, hi = i;
                    while (lo <= hi) {
                        ll mid = (lo+hi) / 2;
                        ll x = spt.query(mid,i);
                        if (x <= b[j]) {
                            right = mid;
                            lo = mid + 1;
                        }
                        else hi = mid - 1;
                    }
                }
                if (right == -1) continue;
                
                if (spt.query(left,i) == b[j]) {
                    ll v = min(dp[j].get(i), dp[j-1].prod(left-1,right) + a[i]);
                    dp[j].set(i,v);
                }
            }
        }
        ll ans = dp[m].get(n);
        if (ans == inf) ans = -1;
        return ans;
    }
};