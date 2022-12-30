using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {

    int n = adj.size();
    queue<vi> q;
    set<vi> s;
    q.push({0});
    s.insert({0});
    vvi ret;

    while (q.size()) {
      auto p = q.front();
      q.pop();
      for (auto v : adj[p.back()]) {
        auto np = p;
        np.push_back(v);
        if (s.count(np)) continue;
        if (v != n-1) q.push(np);
        else ret.push_back(np);
        s.insert(np);
      }
    }
    
    return ret;
  }
};