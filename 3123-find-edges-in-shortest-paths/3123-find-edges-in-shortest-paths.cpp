using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 2e18;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vvp adj(n);
        vi wt(m);
        for (int i=0; i<m; i++) {
            auto e = edges[i];
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
            wt[i] = w;
        }
        min_pq<pii> pq;
        pq.push({0,0});
        vi dist(n,inf);
        dist[0] = 0;
        while (pq.size()) {
            auto [d,u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;
            for (auto [v,i] : adj[u]) {
                ll w = wt[i];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        
        vector<bool> ans(m);
        queue<int> q;
        q.push(n-1);
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (auto [v,i] : adj[u]) {
                ll w = wt[i];
                if (dist[u] == dist[v] + w) {
                    ans[i] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
