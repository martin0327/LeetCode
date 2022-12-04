

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
    int minScore(int n, vector<vector<int>>& roads) {
        using ll = long long;
  using vi = vector<ll>;
  using vvi = vector<vi>;
  using pii = pair<ll,ll>;
  using vp = vector<pii>;
  using vvp = vector<vp>;

  dsu d(n);
  for (auto x : roads) {
    ll u = x[0];
    ll v = x[1];
    ll w = x[2];
    u--; v--;
    d.merge(u,v);
  }
  map<ll,ll> mp;
  for (auto x : roads) {
    ll u = x[0];
    ll v = x[1];
    ll w = x[2];
    u--; v--;
    ll l = d.leader(u);
    if (mp.count(l)) mp[l] = min(mp[l],w);
    else mp[l] = w;
  }
  ll ans = mp[d.leader(0)];
        
        return ans;
    }
};