using vi = vector<int>;
class Solution {
public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    vector<set<int>> adj(n);
    for (auto uv : edges) {
      int u = uv[0];
      int v = uv[1];
      u--; v--;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    
    vi odd;
    for (int i=0; i<n; i++) {
      int sz = adj[i].size();
      if (sz&1) odd.push_back(i);
    }
    int sz = odd.size();
    if (sz==0) return true;
    if (sz&1 || sz > 4) return false;
    if (sz == 2) {
      int u = odd[0];
      int v = odd[1];
      if (!adj[u].count(v)) return true;
      for (int i=0; i<n; i++) {
          if (!adj[i].count(u) && !adj[i].count(v)) return true;
      }
      return false;
    }
    
    if (sz == 4) {
      for (int mask=0; mask<16; mask++) {
        vi a, b;
        for (int i=0; i<sz; i++) {
          if (mask>>i&1) a.push_back(odd[i]);
          else b.push_back(odd[i]);
        }
        if (a.size() != 2) continue;
        bool ok = true;
        {
          int u = a[0];
          int v = a[1];
          if (adj[u].count(v)) ok = false;
        }
        {
          int u = b[0];
          int v = b[1];
          if (adj[u].count(v)) ok = false;
        }
        if (ok) return true;
      }
    }
    return false;
  }
};