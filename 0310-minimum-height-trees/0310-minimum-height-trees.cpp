class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
          typedef vector<int> vi;
          typedef vector<vi> vvi;

          vvi adj(n);
          vi deg(n);
          vi lv(n);
          for (auto p : edges) {
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
          }
          queue<int> q;
          for (int i=0; i<n; i++) {
            if (deg[i]==1) {
              q.push(i);
              lv[i] = 1;
            }
          }
          while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
              if (lv[v] != 0) continue;
              deg[v]--;
              if (deg[v]==1) {
                q.push(v);
                lv[v] = lv[u] + 1;
              }
            }
          }
          int max_lv = 0;
          for (auto x : lv) max_lv = max(max_lv, x);
          vi ans;
          for (int i=0; i<n; i++) {
            if (lv[i] == max_lv) ans.push_back(i);
          }
          return ans;
    }
};