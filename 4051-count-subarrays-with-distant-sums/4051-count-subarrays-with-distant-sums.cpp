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
    long long distantSubarrays(vector<int>& aa, int tg, int k) {
        ll n = aa.size();
        if (k == 0) {
            auto ans = n*(n+1)/2;
            return ans;
        }
        vi a(aa.begin(), aa.end());
        vi pre(n+1);
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + a[i];
        }
        vi cx;
        for (int i=0; i<=n; i++) {
            cx.push_back(pre[i]);
            cx.push_back(pre[i]-tg-k);
            cx.push_back(pre[i]-tg+k);
        }
        cx = get_unique(cx);
        int sz = cx.size();
        fenwick_tree<ll> fen(sz);
        auto g = [&] (ll x) {
            auto it = lower_bound(cx.begin(), cx.end(), x);
            return it - cx.begin();
        };

        ll ans = 0;
        for (int i=0; i<=n; i++) {
            auto lo = g(pre[i]-tg-k);
            auto hi = g(pre[i]-tg+k);
            ans += fen.sum(0,lo+1);
            ans += fen.sum(hi,sz);
            fen.add(g(pre[i]),1);
        }
        return ans;
    }
};