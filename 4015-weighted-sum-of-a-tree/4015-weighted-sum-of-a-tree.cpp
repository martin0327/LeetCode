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

ll n,height;
vi a,b;
vvi adj;

void f(ll u, ll d) {
    b[u] = d;
    for (auto v : adj[u]) {
        f(v,d+1);
    }
}

class Solution {
public:
    long long weightedSum(vector<int>& par, vector<int>& aa) {
        a = vi(aa.begin(), aa.end());
        n = a.size();
        adj = vvi(n);
        for (int i=1; i<n; i++) {
            adj[par[i]].push_back(i);
        }
        b = vi(n);
        f(0,1);
        ll mx = 0;
        for (int i=0; i<n; i++) {
            chmax(mx, b[i]);
        }
        ll ans = 0;
        for (int i=0; i<n; i++) {
            ans += a[i] * (mx-b[i]+1);
        }
        return ans;
    }
};