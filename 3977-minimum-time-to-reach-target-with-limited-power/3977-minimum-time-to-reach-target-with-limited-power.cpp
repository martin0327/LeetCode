
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;
const ll inf = 2e18;

class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edg, int k, vector<int>& a, int src, int tg) {
        vvp adj(n);
        for (auto &t : edg) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v,w});
        }
        vvi dist(n, vi(k+1, inf));
        dist[src][k] = 0;
        min_pq<ti3> pq;
        pq.push({0,k,src});
        while (pq.size()) {
            auto [d,p,u] = pq.top();
            pq.pop();
            if (d > dist[u][p]) continue;
            if (a[u] > p) continue;
            for (auto [v,w] : adj[u]) {
                ll nd = d + w;
                ll np = p - a[u];
                if (nd < dist[v][np]) {
                    dist[v][np] = nd;
                    pq.push({nd,np,v});
                }
            }
        }
        ll ans = inf;
        for (int p=0; p<=k; p++) {
            chmin(ans, dist[tg][p]);
        }
        if (ans == inf) {
            vector<long long> res = {-1,-1};
            return res; 
        }
        ll max_p = -inf;
        for (int p=0; p<=k; p++) {
            if (ans == dist[tg][p]) {
                max_p = p;
            }
        }
        vector<long long> res = {ans, max_p};
        return res;
    }
};