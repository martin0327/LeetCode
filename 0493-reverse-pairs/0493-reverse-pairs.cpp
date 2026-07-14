template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

template <class T> struct fenwick_tree {
    using U = T;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

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

using ll = long long;
class Solution {
public:
    int reversePairs(vector<int>& a) {
        auto cx = get_unique(a);
        auto g = [&] (ll x) {
            auto it = lower_bound(cx.begin(), cx.end(),x);
            return it - cx.begin();
        };
        ll sz = cx.size(), ans = 0;
        fenwick_tree<ll> fen(sz);
        for (ll x : a) {
            ans += fen.sum(g(2*x+1),sz);
            fen.add(g(x),1);
        }
        return ans;
    }
};