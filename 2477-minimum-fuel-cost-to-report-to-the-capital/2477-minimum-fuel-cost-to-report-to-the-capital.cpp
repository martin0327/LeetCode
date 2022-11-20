class Solution {
public:
  using ll = long long;
  using vi = vector<ll>;
  using vvi = vector<vi>;

  ll ans = 0;
  vvi adj;
  ll n, k;

  ll f(int u, int p) {
    ll ret = 1;
    for (auto v : adj[u]) {
      if (v==p) continue;
      ret += f(v,u);
    }
    ans += ret / k + (ret % k > 0);
    return ret;
  }

  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    n = roads.size() + 1;
    k = seats;
    adj = vvi(n);
    for (auto b : roads) {
      ll u = b[0];
      ll v = b[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (auto u : adj[0]) {
      f(u,0);
    }
    return ans;
  }
};