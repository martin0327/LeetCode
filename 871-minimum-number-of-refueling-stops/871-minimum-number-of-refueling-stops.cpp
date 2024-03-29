using ll = long long;
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& a) {
    ll cur = 0;
    ll fuel = startFuel;
    a.push_back({target,0});
    priority_queue<ll> pq;
    for (auto v : a) {
      ll p = v[0];
      ll f = v[1];
      ll d = p - cur;
      ll x = min(d,fuel);
      fuel -= x;
      d -= x;
      while (pq.size() && d > 0) {
        ll ff = pq.top(); pq.pop();
        ll y = min(d,ff);
        d -= y;
        ff -= y;
        if (ff>0) fuel += ff;
      }
      if (d > 0) return -1;
      cur = p;
      pq.push(f);
    }
    int ans = a.size() - pq.size();
    return ans;
  }
};