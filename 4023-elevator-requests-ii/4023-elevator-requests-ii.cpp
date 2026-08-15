template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;

const ll inf = 2e18;
const int sz = 1505;
ll dp[sz][sz][2];
bool vis[sz][sz][2];
int n, src;
vi a;

ll f(int l, int r, int j) {
    if (vis[l][r][j]) return dp[l][r][j];
    vis[l][r][j] = 1;
    ll ret = inf;
    if (l == r) {
        if (l == src) return dp[l][r][j] = 0;
        else return dp[l][r][j] = ret;
    }
    if (j == 0) {
        if (f(l+1,r,0) < inf) {
            chmin(ret, f(l+1,r,0) + (a[l+1]-a[l]) * (n-(r-l)));
        }
        if (f(l+1,r,1) < inf) {
            chmin(ret, f(l+1,r,1) + (a[r]-a[l]) * (n-(r-l)));
        }
    }
    else {
        if (f(l,r-1,0) < inf) {
            chmin(ret, f(l,r-1,0) + (a[r]-a[l]) * (n-(r-l)));
        }
        if (f(l,r-1,1) < inf) {
            chmin(ret, f(l,r-1,1) + (a[r]-a[r-1]) * (n-(r-l)));
        }
    }
    return dp[l][r][j] = ret;
}

class Solution {
public:
    long long elevatorRequests(int m, int start, vector<int>& aa) {
        a = vi(aa.begin(), aa.end());
        src = start;
        a.push_back(src);
        a = get_unique(a);
        n = a.size();
        auto g = [&] (ll x) {
            auto it = lower_bound(a.begin(), a.end(), x);
            return it - a.begin();
        };
        src = g(src);
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        
        ll ans = min(f(0,n-1,0), f(0,n-1,1));
        return ans;
    }
};