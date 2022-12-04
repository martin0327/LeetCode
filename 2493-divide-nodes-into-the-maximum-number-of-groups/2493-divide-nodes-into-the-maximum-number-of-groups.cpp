
#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

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

}  // namespace atcoder

using namespace atcoder;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        dsu d(n);
  using vi = vector<int>;
  using vvi = vector<vi>;
  const int inf = 1e9;
  vvi adj(n);
  for (auto x : edges) {
    int u = x[0];
    int v = x[1];
    u--; v--;
    d.merge(u,v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  bool ok = true;
  // debug(d.groups().size());
  vi dist(n,inf);
  for (auto grp : d.groups()) {
    // if (grp.size()==1) continue;
    int max_d = 0;
    for (auto i : grp) {
      int root = i;
      queue<int> q;
      q.push(root);
      for (auto j : grp) dist[j] = inf;
      dist[root] = 0;
      
      while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
          if (dist[v] == inf) {
            dist[v] = dist[u] + 1;
            q.push(v);
            max_d = max(max_d, dist[v]);
          }
          else if (dist[v] >= dist[u] && dist[v] != dist[u] + 1) ok = false;
        }
      }
      // debug(dist);
    }
    if (ok) ans += max_d+1;
  }
        if (ok) return ans;
        else return -1;
    }
};