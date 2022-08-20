using ll = long long;

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& a) {
    int n = a.size();
    ll cur = 0;
    ll fuel = startFuel;
    a.push_back({target,0});
    priority_queue<ll> pq;
    for (auto v : a) {
      // debug(cur);
      ll p = v[0];
      // debug(p);
      ll f = v[1];
      ll d = p - cur;
      ll x = min(d,fuel);
      // debug(fuel,d);
      fuel -= x;
      d -= x;
      // debug(x,fuel,d);
      while (pq.size() && d > 0) {
        ll ff = pq.top();
        // debug(f);
        pq.pop();
        // debug(pq.size());
        ll y = min(d,ff);
        d -= y;
        ff -= y;
        if (ff>0) fuel += ff;
      }
      if (d > 0) return -1;
      cur = p;
      pq.push(f);
    }
    int ans = n - pq.size() + 1;
    return ans;
  }
};