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

  private:
    int _n;
    std::vector<int> parent_or_size;
};

class Solution {
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    using vi = vector<int>;
    using vvi =vector<vi>;
    
    int n = vals.size();
    vvi adj(n);
    for (auto uv : edges) {
      int u = uv[0];
      int v = uv[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    map<int,vi> mp;
    for (int i=0; i<n; i++) mp[vals[i]].push_back(i);

    int ans = n;
    dsu d(n);
    for (auto &[val, a] : mp) {
      for (auto &u : a) {
        for (auto &v : adj[u]) {
          if (vals[v] <= vals[u]) d.merge(u,v);
        }
      }
      map<int,int> cnt;
      for (auto &u : a) cnt[d.leader(u)]++;
      for (auto &[k,v] : cnt) ans += v * (v-1) / 2;
    }
    return ans;
  }
};  