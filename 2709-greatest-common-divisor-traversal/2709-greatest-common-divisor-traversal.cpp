
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }


  private:
    int _n;
    std::vector<int> parent_or_size;
};

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& a) {
        int n = a.size(), sz = 1e5;
        vvi inv(sz+1);
        for (int i=0; i<n; i++) {
            inv[a[i]].push_back(i);
        }
        vi is_prime(sz+1, 1);
        dsu d(n);
        for (int i=2; i<=sz; i++) {
            int idx = -1;
            if (is_prime[i]) {
                for (int j=i; j<=sz; j+=i) {
                    is_prime[j] = 0;
                    if (inv[j].size()) {
                        if (idx == -1) idx = inv[j].front();
                        for (auto k : inv[j]) {
                            d.merge(idx,k);
                        }
                    }
                }
            }
        }
        bool ans = (d.size(0) == n);
        return ans;
    }
};