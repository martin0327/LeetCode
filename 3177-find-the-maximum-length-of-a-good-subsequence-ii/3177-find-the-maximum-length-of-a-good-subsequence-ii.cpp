using ll = long long;
using vi = vector<ll>;
const ll inf = 2e18;

using S = ll;
S op(S x, S y) { return max(x,y); }
S e() { return -inf; }

struct segtree {
  public:
    segtree(int n) {
        _n = n, log = 0;
        while ((1ll<<log) < n) log++;
        size = 1 << log;
        d = vector<S>(2 * size, e());
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
    vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        vi a(nums.begin(), nums.end());
        vi comp = a;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        ll sz = comp.size();
        for (auto &x : a) x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();

        
        vector<segtree> dp(k+1, segtree(sz));

        for (auto x : a) {
            if (dp[0].get(x) == -inf) dp[0].set(x,1);
            else {
                for (int i=0; i<=k; i++) {
                    ll v = dp[i].get(x);
                    if (v != inf) dp[i].set(x,v+1);
                }
            }
            for (int i=0; i<k; i++) {
                ll v = dp[i].prod(0,x);
                v = max(v, dp[i].prod(x+1,sz));
                if (dp[i+1].get(x) <= v) dp[i+1].set(x,v+1);
            }
        }
        
        ll ans = 0;
        for (int i=0; i<=k; i++) {
            ans = max(ans, dp[i].all_prod());
        }
        return ans;
    }
};