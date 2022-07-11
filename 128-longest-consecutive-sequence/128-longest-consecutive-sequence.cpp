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
    int longestConsecutive(vector<int>& a) {
        if (a.empty()) return 0;
        unordered_map<int,int> mp;
        int n = 0;
        for (auto x : a) {
            if (!mp.count(x)) mp[x] = n++;
        }
        dsu d(n);
        for (auto x : a) {
            if (mp.count(x-1)) {
                d.merge(mp[x],mp[x-1]);
            }
            if (mp.count(x+1)) {
                d.merge(mp[x],mp[x+1]);
            }
        }
        int ans = 0;
        for (auto grp : d.groups()) {
            ans = max(ans, (int) grp.size());
        }
        return ans;
    }
};