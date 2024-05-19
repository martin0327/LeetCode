using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
// using vm = vector<mint>;
// using vvm = vector<vm>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;


template<typename T>
void chmax(T &x, T y) {x = max(x,y);}


template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int kk, vector<vector<int>>& edges) {
        int n = nums.size();
        vi a(nums.begin(), nums.end());
        ll k = kk;
        vvi adj(n);
        for (auto uv : edges) {
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vvi dp(n, vi(2,-1));

        // debug(a);
        // debug(k);
        // debug(adj);

        function<ll(ll,ll,ll)> f = [&] (ll u, ll p, ll j) {
            // debug(u,p,j);
            if (dp[u][j] != -1) return dp[u][j];
            ll sz = adj[u].size()-1;
            if (u==0) sz++;

            if (sz == 0) {
                if (j) return dp[u][j] = (a[u] ^ k);
                else return dp[u][j] = a[u];
            }

            vvi b(sz, vi(2));
            int i = 0;
            for (auto v : adj[u]) {
                if (v==p) continue;
                b[i][0] = f(v,u,0);
                b[i][1] = f(v,u,1);
                i++;
            }
            vvi dp2(sz, vi(2));
            dp2[0][0] = b[0][0];
            dp2[0][1] = b[0][1];
            for (int i=0; i+1<sz; i++) {
                for (int j=0; j<2; j++) {
                    for (int l=0; l<2; l++) {
                        chmax(dp2[i+1][(j+l)%2],dp2[i][j]+b[i+1][l]); 
                    }
                }
            }
            ll ret = 0;
            if (j) {
                chmax(ret, dp2[sz-1][0] + (a[u]^k));
                chmax(ret, dp2[sz-1][1] + a[u]);
            }
            else {
                chmax(ret, dp2[sz-1][0] + a[u]);
                chmax(ret, dp2[sz-1][1] + (a[u]^k));
            }
            return dp[u][j] = ret;
        };


        ll ans = f(0,-1,0);
        return ans;

        
    }
};