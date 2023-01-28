template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<ll,ll>;
using vp = vector<pii>;

class Solution {
public:
  long long maxScore(vector<int>& a, vector<int>& b, int k) {
    ll n = a.size();
    vp c(n);
    for (int i=0; i<n; i++) c[i] = {b[i], a[i]};
    sort(c.rbegin(), c.rend());
    ll ans = 0;
    ll s = 0;
    min_pq<ll> pq;
    for (auto [y,x] : c) {
      pq.push(x);
      s += x;
      if (pq.size() > k) {
        s -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) ans = max(ans, s * y);
    }
    return ans;
  }
};