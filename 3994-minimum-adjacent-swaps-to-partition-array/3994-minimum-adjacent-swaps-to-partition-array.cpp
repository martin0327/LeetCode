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

using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& a, ll lo, ll hi) {
        map<ll,vi> mp;
        ll n = a.size(), idx = 0, ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] < lo) mp[0].push_back(i);
            else if (a[i] > hi) mp[2].push_back(i);
            else mp[1].push_back(i);
        }
        vi tg(n,-1);
        for (auto [k,v] : mp) {
            for (auto i : v) {
                tg[i] = idx++;
            }
        }
        fenwick_tree<ll> fen(n);
        for (auto x : tg) {
            ans += fen.sum(x,n);
            fen.add(x,1);
        }
        ans %= mod;
        return ans;
    }
};