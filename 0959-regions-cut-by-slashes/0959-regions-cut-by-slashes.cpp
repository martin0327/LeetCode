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

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ti3 = tuple<int,int,int>;

class Solution {
public:
    int regionsBySlashes(vector<string>& a) {
        char sl = '/', bs = '\\';
        int n = a.size();
        vvvi b(n, vvi(n, vi(2)));
        vector<pair<ti3,ti3>> e;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j] == ' ') {
                    ti3 u = {i,j,0};
                    ti3 v = {i,j,1};
                    e.push_back({u,v});
                }
                if (i+1 < n) {
                    ti3 u = {i,j,1};
                    ti3 v = {i+1,j,0};
                    e.push_back({u,v});
                }
                if (j+1 < n) {
                    if (a[i][j] != sl && a[i][j+1] != bs) {
                        ti3 u = {i,j,0};
                        ti3 v = {i,j+1,0};
                        e.push_back({u,v});
                    }
                    if (a[i][j] != bs && a[i][j+1] != sl) {
                        ti3 u = {i,j,1};
                        ti3 v = {i,j+1,1};
                        e.push_back({u,v});
                    }
                    if (a[i][j] == sl && a[i][j+1] == sl) {
                        ti3 u = {i,j,1};
                        ti3 v = {i,j+1,0};
                        e.push_back({u,v});
                    }
                    if (a[i][j] == bs && a[i][j+1] == bs) {
                        ti3 u = {i,j,0};
                        ti3 v = {i,j+1,1};
                        e.push_back({u,v});
                    }
                }
            }
        }
        dsu d(n*n*2);
        for (auto [u,v] : e) {
            int x, y;
            {
                auto [i,j,k] = u;
                x = 2*(i*n+j)+k;
            }
            {
                auto [i,j,k] = v;
                y = 2*(i*n+j)+k;
            }
            d.merge(x,y);
        }
        // for (auto [u,v] : e) {
        //     debug(u,v);
        // }
        int ans = d.groups().size();
        return ans;
        
    }
};