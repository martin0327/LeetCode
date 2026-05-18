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

using ll = int;
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edg) {
        vvi adj(n);
        dsu uf(n);
        vi a(n, -1), vis(n);
        int ans = 0;
        for (auto &uvw : edg) {
            int u = uvw[0], v = uvw[1], w = uvw[2];
            auto g = [&] (int u, int v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                uf.merge(u,v);
                ans++;
            };
            if (a[u] == -1 && a[v] == -1) {
                a[u] = 0;
                a[v] = a[u] ^ w;
                g(u,v);
            }
            else if (a[u] == -1) {
                a[u] = a[v] ^ w;
                g(u,v);
            }
            else if (a[v] == -1) {
                a[v] = a[u] ^ w;
                g(u,v);
            }
            else {
                if (uf.same(u,v)) {
                    if (a[u] ^ a[v] == w) {
                        g(u,v);
                    }
                }
                else {
                    if (a[u] ^ a[v] != w) {
                        int sz1 = uf.size(u);
                        int sz2 = uf.size(v);
                        auto f = [&] (int src) {
                            vis.assign(n, 0);
                            vis[src] = 1;
                            queue<int> q;
                            q.push(src);
                            while (q.size()) {
                                auto u = q.front();
                                q.pop();
                                a[u] ^= 1;
                                for (auto v : adj[u]) {
                                    if (vis[v]) continue;
                                    vis[v] = 1;
                                    q.push(v);
                                }
                            }
                        };
                        if (sz1 < sz2) f(u);
                        else f(v);
                    }
                    g(u,v);
                }
            }
        }
        return ans;
    }
};