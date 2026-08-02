template <class T> struct fenwick_tree {
    using U = T;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    long long countRatioSubarrays(vector<int>& cc, ll a, ll b) {
        vi c(cc.begin(), cc.end());
        ll n = c.size();
        vi p(n+1);
        for (int i=1; i<=n; i++) {
            p[i] = p[i-1] + (c[i-1]&1);
        }
        vi cx;
        for (ll i=0; i<=n; i++) {
            cx.push_back(p[i]*(a+b)-b*i);
        }
        cx = get_unique(cx);
        auto g = [&] (ll x) {
            auto it = lower_bound(cx.begin(), cx.end(), x);
            return it - cx.begin();
        };
        ll sz = cx.size();
        fenwick_tree<ll> fen(sz);
        ll ans = 0;
        for (ll i=0; i<=n; i++) {
            ll t = p[i]*(a+b)-b*i;
            auto idx = g(t);
            ans += fen.sum(0,idx+1);
            fen.add(idx,1);
        }
        return ans;
    }
};