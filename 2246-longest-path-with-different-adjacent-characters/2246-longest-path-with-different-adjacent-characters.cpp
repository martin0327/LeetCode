
class Solution {
public:
  using vi = vector<int>;
  using vvi = vector<vi>;

  vvi adj;
  string s;
  int ans=0;

  int f(int u) {
    int a = 0, b = 0;
    for (auto v : adj[u]) {
      int cnt = f(v);
      if (s[u] != s[v]) {
        if (cnt >= a) {
          b = a;
          a = cnt; 
        }
        else if (cnt > b) b = cnt; 
      }
    }
    ans = max(ans, 1+a+b);
    return a+1;
  }
    
  int longestPath(vector<int>& par, string _s) {
    s = _s;
    int n = par.size();
    adj.resize(n);

    for (int i=1; i<n; i++) adj[par[i]].push_back(i);
    
    f(0);
    
    return ans;

  }
};