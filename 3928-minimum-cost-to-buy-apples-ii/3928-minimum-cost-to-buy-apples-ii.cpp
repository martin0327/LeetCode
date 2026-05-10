template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
const ll inf = 2e18;

class Solution {
public:
    vector<int> minCost(int n, vector<int>& a, vector<vector<int>>& rd) {
        vvp adj1(n), adj2(n);
        for (auto &t : rd) {
            ll u = t[0], v = t[1], w = t[2], x = t[3];
            x *= w;
            adj1[u].push_back({v,w});
            adj1[v].push_back({u,w});
            adj2[u].push_back({v,x});
            adj2[v].push_back({u,x});
        }
        vvi dist1(n, vi(n, inf));
        vvi dist2(n, vi(n, inf));

        auto f = [&] (int src, vi &dist, vvp &adj) {
            min_pq<pii> pq;
            pq.push({0,src});
            dist[src] = 0;
            while (pq.size()) {
                auto [d,u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto [v,w] : adj[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.push({dist[v],v});
                    }
                }
            }
        };

        for (int i=0; i<n; i++) {
            f(i,dist1[i],adj1);
            f(i,dist2[i],adj2);
        }

        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            ll t = a[i];
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                chmin(t, dist1[i][j] + dist2[j][i] + a[j]);
            }
            ans[i] = t;
        }
        return ans;
    }
};