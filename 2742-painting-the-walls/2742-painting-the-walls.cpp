using ld = long double;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T>
void chmax(T &x, T y) {x = max(x,y);}
template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

class Solution {
public:
    int paintWalls(vector<int>& a, vector<int>& b) {
        ll n = a.size(), m = 0, tot = 0;
        for (auto t : b) m += t;
        for (auto c : a) tot += c;

        vi dp1(m+1, -1);
        vi dp2 = dp1;
        dp1[0] = 0;
        for (ll i=0; i<n; i++) {
            dp2 = dp1;
            for (ll j=0; j<m; j++) {
                ll nj = j + b[i] + 1;
                if (nj <= m) chmax(dp2[nj],dp1[j]+a[i]);
            }
            dp1 = dp2;
        }
        
        ll ans = tot - *max_element(dp1.begin(), dp1.end());
        return ans;
    }
};