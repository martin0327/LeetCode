using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

struct dsu {
    int n;
    vi a;
    
    dsu (int n) {
        this->n = n;
        a = vi(n, -1);
    }
    
    int leader(int x) {
        if (a[x] < 0) return x;
        return a[x] = leader(a[x]);
    }
    
    void merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x==y) return;
        if (-a[x] < -a[y]) swap(x,y);
        a[x] += a[y];
        a[y] = x;
    }
    
    int size(int x) {
        return -a[leader(x)];
    }
    
};

ll sq(ll x) {return x*x;}

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b) {
        int n = b.size();
        vvi adj(n);
        for (int i=0; i<n; i++) {
            vi x = b[i];
            int x1 = x[0], y1 = x[1], r1 = x[2];
            for (int j=i+1; j<n; j++) {
                vi y = b[j];
                int x2 = y[0], y2 = y[1], r2 = y[2];
                if (sq(x1-x2) + sq(y1-y2) <= sq(r1)) {
                    adj[i].push_back(j);
                }
                if (sq(x1-x2) + sq(y1-y2) <= sq(r2)) {
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        function<int(int)> f = [&] (int x) {
            vi check(n);
            check[x] = 1;
            int ret = 1;
            queue<int> q;
            q.push(x);
            while (q.size()) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    if (check[v]) continue;
                    check[v] = 1;
                    q.push(v);
                    ret++;
                }
            }
            return ret;
        };
        for (int i=0; i<n; i++) ans = max(ans, f(i));
        return ans;
    }
};