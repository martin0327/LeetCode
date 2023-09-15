struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
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
    vector<int> parent_or_size;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& a) {
        int n = a.size();
        vector<tuple<int,int,int>> b;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int x1 = a[i][0], y1 = a[i][1];
                int x2 = a[j][0], y2 = a[j][1];
                b.emplace_back(abs(x1-x2)+abs(y1-y2),i,j);
            }
        }
        sort(b.begin(), b.end());
        dsu d(n);
        int ans = 0;
        for (auto [w,u,v] : b) {
            if (!d.same(u,v)) {
                d.merge(u,v);
                ans += w;
            }
            if (d.size(0) == n) break;
        }
        return ans;
    }
};