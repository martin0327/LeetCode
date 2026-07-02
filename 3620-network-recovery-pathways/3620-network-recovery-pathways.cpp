template<typename T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pii>;
using vvp = vector<vp>;
const ll inf = 2e18;
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edg, vector<bool>& b, long long k) {
        ll n = b.size(), m = edg.size();
        vvp adj1(n), adj2(n);
        vi ws;
        for (int i=0; i<m; i++) {
            auto &t = edg[i];
            int u = t[0], v = t[1], w = t[2];
            if (!b[u] || !b[v]) continue;
            ws.push_back(w);
            adj1[u].push_back({v,w});
            adj2[v].push_back({u,w});
        }
        sort(ws.begin(), ws.end());
        ws.erase(unique(ws.begin(), ws.end()), ws.end());
        auto g = [&] (ll x) {
            auto it = lower_bound(ws.begin(), ws.end(), x);
            return it - ws.begin();
        };
        int sz = ws.size();
        vvp a(sz);
        for (int i=0; i<n; i++) {
            int u = i;
            for (auto [v,w] : adj1[u]) {
                auto j = g(w);
                a[j].push_back({u,v});
            }
        }
        auto f = [&] (ll src, vvp &adj, vi &dist, ll lim) {
            dist = vi(n, inf);
            dist[src] = 0;
            min_pq<pii> pq;
            pq.push({0,src});
            while (pq.size()) {
                auto [d,u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto [v,w] : adj[u]) {
                    if (w < lim) continue;
                    ll nd = d + w;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        pq.push({nd,v});
                    }
                }
            }
        };
        ll lo = 0, hi = sz-1, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            auto w = ws[mid];
            vi dist1, dist2;
            f(0,adj1,dist1,w);
            bool ok = dist1[n-1] <= k;
            if (ok) {
                ans = w;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};