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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& e) {
        if (e.size() < n-1) return -1;
        dsu d(n);
        for (auto uv : e) {
            int u = uv[0], v = uv[1];
            if (!d.same(u,v)) {
                d.merge(u,v);
                n--;
            }
        }
        return n - 1;
    }
};