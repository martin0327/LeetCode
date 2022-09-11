template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<ll,ll>;
using vp = vector<pii>;

const int mod = 1e9+7;
void chmin(ll &x, ll y) {x = min(x,y);}
void chmax(ll &x, ll y) {x = max(x,y);}

class Solution {
public:
    int maxPerformance(int n, vector<int>& a, vector<int>& b, int k) {
        vp c(n);
        for (int i=0; i<n; i++) c[i] = {b[i],a[i]};
        sort(c.rbegin(), c.rend());
        min_pq<ll> pq;
        ll ans = 0;
        ll s = 0;
        ll min_b = 1e9;
        for (int i=0; i<n; i++) {
            auto [y,x] = c[i];
            chmin(min_b, y);
            pq.push(x);
            s += x;
            while (pq.size() > k) {
                s -= pq.top();
                pq.pop();                
            }
            chmax(ans, s * min_b);            
        }
        ans %= mod;
        return ans;
    }
};