using ll = long long;
class Solution {
public:
  long long pickGifts(vector<int>& a, int k) {
    priority_queue<ll> pq;
    for (auto x : a) pq.push(x);
    while (pq.size() && k--) {
      ll x = pq.top(); pq.pop();
      pq.push((ll) sqrt(x));
    }
    ll ans = 0;
    while (pq.size()) {
      ans += pq.top(); pq.pop();
    }
    return ans;
  }
};