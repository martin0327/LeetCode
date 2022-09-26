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

    std::vector<std::vector<int>> groups() {
      std::vector<int> leader_buf(_n), group_size(_n);
      for (int i = 0; i < _n; i++) {
        leader_buf[i] = leader(i);
        group_size[leader_buf[i]]++;
      }
      std::vector<std::vector<int>> result(_n);
      for (int i = 0; i < _n; i++) {
        result[i].reserve(group_size[i]);
      }
      for (int i = 0; i < _n; i++) {
        result[leader_buf[i]].push_back(i);
      }
      result.erase(
        std::remove_if(result.begin(), result.end(),
                        [&](const std::vector<int>& v) { return v.empty(); }),
        result.end());
      return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<pair<int,int>> a,b;
        for (auto eq : equations) {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            if (eq[1] == '=') a.push_back({u,v});
            else b.push_back({u,v});
        }
        dsu d(26);
        for (auto [u,v] : a) {
            d.merge(u,v);
        }
        for (auto [u,v] : b) {
            if (d.same(u,v)) return false;
        }
        return true;        
    }
};             