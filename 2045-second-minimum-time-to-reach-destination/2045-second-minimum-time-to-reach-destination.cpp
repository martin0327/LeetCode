using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using ti3 = tuple<ll,ll,ll>;
const ll inf = 2e18;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int ch) {
        vvi adj(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        min_pq<ti3> pq;
        pq.emplace(0,0,0);

        vvi dist(n, vi(2,inf));
        dist[0][0] = 0;

        vi res;
        while (pq.size()) {
            auto [d,u,fs] = pq.top();
            pq.pop();
            if (d > dist[u][fs])  continue;

            for (auto v : adj[u]) {
                ll nd = d + time;
                if (v == n-1) res.push_back(nd);
                
                ll q = nd / ch;
                if (q&1) nd = (q+1)*ch;
                if (dist[v][0] > nd) {
                    pq.emplace(dist[v][0]=nd,v,0);
                }
                else if (dist[v][0] < nd && nd < dist[v][1]) {
                    pq.emplace(dist[v][1]=nd,v,1);
                }
            }
        }
        res = get_unique(res);
        ll ans = res[1];
        return ans;
        
    }
};
