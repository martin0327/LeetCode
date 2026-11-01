
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
    sort(a.begin(), a.end());
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
using vvs = vector<vs>;

const ll inf = 2e18;
class Solution {
public:
    int minActivationCost(vector<vector<int>>& edg, vector<int>& a) {
        int n = a.size();
        vvp adj(n);
        for (auto &e : edg) {
            auto u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vi par(n,-1), wt(n);
        function<void(int,int)> f = [&] (int u, int p) {
            par[u] = p;
            a[u] = __builtin_popcount(a[u])&1;
            for (auto [v,w] : adj[u]) {
                if (v == p) continue;
                wt[v] =  w;
                f(v,u);
            }
        };
        f(0,-1);
        ll ans = inf;
        function<vi(int,int)> g = [&] (int u, int p) {
            vi ret = {inf,inf};
            vi cur = {inf,inf};
            ret[a[u]] = wt[u];
            for (auto [v,w] : adj[u]) {
                if (v == p) continue;
                auto t = g(v,u);
                chmin(ans, t[a[u]]);
                for (int i=0; i<2; i++) {
                    chmin(ret[i^a[u]], t[i]+wt[u]);
                    if (a[u]) {
                        chmin(ans, cur[i^1]+t[i]);
                    }
                    else {
                        chmin(ans, cur[i]+t[i]);
                    }
                    chmin(cur[i], t[i]);
                }
            }
            return ret;
        };
        g(0,-1);
        if (ans == inf) ans = -1;
        return ans;
    }
};