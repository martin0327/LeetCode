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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& qr) {
        dsu d(n);
        
        vector<array<int,3>> wuv;
        for (auto a : e) wuv.push_back({a[2],a[0],a[1]});
        sort(wuv.rbegin(), wuv.rend());

        int q = qr.size();
        vector<array<int,4>> off(q);
        for (int i=0; i<q; i++) {
            auto a = qr[i];
            off[i] = {a[2],a[0],a[1],i};
        }
        sort(off.begin(), off.end());
        
        vector<bool> ans(q);
        for (auto [w,u,v,i] : off) {
            while (wuv.size()) {
                auto [w2,u2,v2] = wuv.back();
                if (w2 < w) {
                    wuv.pop_back();
                    d.merge(u2,v2);
                }
                else break;
            }
            ans[i] = d.same(u,v);
        }
        return ans;
    }
};