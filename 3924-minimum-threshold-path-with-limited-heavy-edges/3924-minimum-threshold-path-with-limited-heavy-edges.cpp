

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
const ll inf = 2e18;

class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int tg, int k) {
        ll lo = 0, hi = 1e9, ans = -1;
        vvp adj;
        vi dist;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            adj = vvp(n);
            for (auto &t : edges) {
                int u = t[0], v = t[1], w = t[2];
                if (w <= mid) {
                    adj[u].push_back({v,0});
                    adj[v].push_back({u,0});
                }
                else {
                    adj[u].push_back({v,1});
                    adj[v].push_back({u,1});
                }
            }
            dist = vi(n, inf);
            dist[src] = 0;
            min_pq<pii> pq;
            pq.push({0,src});
            while (pq.size()) {
                auto [d,u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto [v,w] : adj[u]) {
                    if (w + d < dist[v]) {
                        dist[v] = w+d;
                        pq.push({dist[v],v});
                    }
                }
            }
            if (dist[tg] <= k) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;

        }
        return ans;
        
    }
};