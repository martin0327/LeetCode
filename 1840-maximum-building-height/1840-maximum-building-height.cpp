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
vector<T> get_unique(vector<T> a) {
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
const ll inf = 2e18;

class Solution {
public:
    int maxBuilding(int m, vector<vector<int>>& rs) {
        vp a;
        a.push_back({1,0});
        for (auto &v : rs) {
            auto x = v[0], y = v[1];
            a.push_back({x,y});
        }
        vi cx;
        for (auto [x,y] : a) {
            cx.push_back(x);
        }
        cx = get_unique(cx);
        if (cx.back() < m) {
            cx.push_back(m);
        }
        int n = cx.size();
        auto g = [&] (ll x) {
            auto it = lower_bound(cx.begin(), cx.end(), x);
            return it - cx.begin();
        };
        vi b(n,inf);
        for (auto [x,y] : a) {
            auto i = g(x);
            chmin(b[i], y);
        }
        min_pq<pii> pq;
        for (int i=0; i<n; i++) {
            pq.push({b[i],i});
        }
        vi vis(n);
        while (pq.size()) {
            auto [w,i] = pq.top();
            pq.pop();
            if (vis[i]) continue;
            vis[i] = 1;
            if (i > 0) {
                if (vis[i-1] == 0) {
                    int d = cx[i] - cx[i-1];
                    if (w+d < b[i-1]) {
                        chmin(b[i-1], w+d);
                        pq.push({w+d, i-1});
                    }
                }
            }
            if (i+1 < n) {
                if (vis[i+1] == 0) {
                    int d = cx[i+1] - cx[i];
                    if (w+d < b[i+1]) {
                        chmin(b[i+1], w+d);
                        pq.push({w+d, i+1});
                    }
                }
            }
        }
        ll ans = 0;
        for (int i=1; i<n; i++) {
            ll dx = cx[i] - cx[i-1];
            ll y1 = b[i-1], y2 = b[i];
            ll dy = abs(y1-y2);
            chmax(ans, max(y1,y2));
            if (dx > dy) {
                chmax(ans, max(y1,y2) + (dx-dy)/2);
            }
        }
        return ans;
    }
};   