using ll = long long;
using vi = vector<ll>;

struct dsu {
    int n; 
    vi a;
    dsu(int n) {
        this->n = n;
        a = vi(n,-1);
    }
    
    ll leader(int u) {
        if (a[u] < 0) return u;
        return a[u] = leader(a[u]);
    }
    
    ll same(int u, int v) {
        return leader(u) == leader(v);
    }
    
    void merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        ll sz1 = size(u);
        ll sz2 = size(v);
        if (sz1 < sz2) swap(u,v);
        a[v] = u;
        a[u] = -(sz1+sz2);
    }
    
    ll size(int u) {
        return -a[leader(u)];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu d1(n), d2(n);
        sort(edges.rbegin(), edges.rend());
        int cnt = 0;
        for (auto e : edges) {
            ll tp = e[0], u = e[1], v = e[2];
            u--; v--;
            if (tp==1) {
                if (d1.same(u,v)) continue;
                d1.merge(u,v);
                cnt++;
            }
            else if (tp==2) {
                if (d2.same(u,v)) continue;
                d2.merge(u,v);
                cnt++;
            }
            else {
                if (d1.same(u,v)) continue;
                d1.merge(u,v);
                d2.merge(u,v);
                cnt++;
            }
        }
        ll ans = -1;
        if (d1.size(0)==n && d2.size(0)==n) {
            ans = edges.size() - cnt;
        }
        return ans;
    }
};