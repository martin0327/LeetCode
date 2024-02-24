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
    vector<int> findAllPeople(int n, vector<vector<int>>& a, int x) {
        dsu d(n);
        vector<tuple<int,int,int>> b;
        for (auto v : a) {
            b.push_back({v[2],v[0],v[1]});
        }
        sort(b.rbegin(), b.rend());
        d.merge(0,x);

        while (b.size()) {
            auto [t,xx,yy] = b.back();
            map<int,set<int>> adj;
            queue<int> q;
            set<int> check;
            while (b.size()) {
                auto [tt,x,y] = b.back();
                if (tt == t) {
                    if (d.same(0,x) && d.same(x,y)) {
                        b.pop_back();
                        continue;
                    }
                    adj[x].insert(y);
                    adj[y].insert(x);
                    if (d.same(0,x)) {
                        q.push(y);
                        check.insert(x);
                        check.insert(y);
                    }
                    if (d.same(0,y)) {
                        q.push(x);
                        check.insert(x);
                        check.insert(y);
                    }
                    b.pop_back();
                }
                else break;
            }
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (check.count(v)) continue;
                    check.insert(v);
                    q.push(v);
                }
            }
            for (auto u : check) {
                if (!d.same(0,u)) d.merge(0,u);
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (d.same(0,i)) ans.push_back(i);
        }
        return ans;
    }
};