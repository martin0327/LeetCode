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

using S = int;
S op (S x, S y) { return max(x,y); }
S e() { S ret = 0; return ret; }

class Solution {
public:
    int maxSelectedElements(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        map<int,vector<int>> mp;
        for (int i=0; i<n; i++) {
            mp[a[i]].push_back(i);
        }
        segtree<S,op,e> dp0(n), dp1(n);
        for (int i=0; i<n; i++) {
            dp0.set(i,1);
            dp1.set(i,1);
        }
        for (int i=1; i<n; i++) {
            if (mp.count(a[i]-2)) {
                int l = mp[a[i]-2].front();
                int r = mp[a[i]-2].back();
                dp0.set(i,max(dp0.get(i), dp1.prod(l,r+1)+1));
            }
            if (mp.count(a[i])) {
                int l = mp[a[i]].front();
                if (l < i) {
                    auto it = lower_bound(mp[a[i]].begin(), mp[a[i]].end(), i);
                    if (it != mp[a[i]].begin()) {
                        it--;
                        int r = *it;
                        dp1.set(i,max(dp1.get(i), dp0.prod(l,r+1)+1));
                    }
                }
            }
            if (mp.count(a[i]-1)) {
                int l = mp[a[i]-1].front();
                int r = mp[a[i]-1].back();
                dp1.set(i,max(dp1.get(i), dp1.prod(l,r+1)+1));
                dp0.set(i,max(dp0.get(i), dp0.prod(l,r+1)+1));
            }
            
        }
        int ans = max(dp0.all_prod(), dp1.all_prod());
        return ans;
    }
};