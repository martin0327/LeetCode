template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vp = vector<pii>;
using vvp = vector<vp>;
const int inf = 2e9;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dst, int tg) {
        int m = edges.size();
        vi w(m);
        vvp adj(n);
        for (int i=0; i<m; i++) {
            auto e = edges[i];
            int u = e[0], v = e[1];
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
            w[i] = e[2];
        }

        bool done = false, fail = false;
        
        vi dist(n,inf);

        auto f = [&] () {
            dist.assign(n,inf);
            min_pq<pii> pq;
            dist[src] = 0;
            pq.push({0,src});
            while (pq.size()) {
                auto [d,u] = pq.top();
                pq.pop();
                if (dist[u] > d) continue;
                for (auto [v,i] : adj[u]) {
                    int nd = dist[u] + abs(w[i]);
                    if (dist[v] > nd) {
                        pq.push({dist[v] = nd, v});
                    }
                }
            }
            if (dist[dst] == tg) {
                done = true;
                return;
            }
            if (dist[dst] > tg) {
                fail = true;
                return;
            }

            queue<int> q;
            vi vis(n);
            q.push(dst);
            vis[dst] = 1;
            int delta = tg - dist[dst];
            int idx = -1;
            while (q.size()) {
                if (idx != -1) break;
                auto u = q.front();
                q.pop();
                for (auto [v,i] : adj[u]) {
                    if (dist[v] + abs(w[i]) == dist[u]) {
                        if (w[i] == -1) idx = i;
                        if (!vis[v]) {
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
            if (idx != -1) {
                w[idx] = delta + 1;
            }
            else {
                fail = true;
            }
        };

        while (true) {
            if (done) {
                for (int i=0; i<m; i++) {
                    edges[i][2] = abs(w[i]);
                }
                return edges;
            }
            if (fail) {
                edges.clear();
                return edges;
            }
            f();
        }
        
    }
};