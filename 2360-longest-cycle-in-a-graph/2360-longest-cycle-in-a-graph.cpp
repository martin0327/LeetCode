class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

      using vi = vector<int>;

      vi check(n, -1);
      vi dist(n, -1);

      int ans = -1;

      for (int i=0; i<n; i++) {
        if (check[i] != -1) continue;
        queue<int> q; 
        // debug(i);
        q.push(i);
        check[i] = i;
        dist[i] = 0;
        while (q.size()) {
          int u = q.front();
          q.pop();
          int v = edges[u];
          if (v==-1) continue;
          if (check[v] == -1) {
            check[v] = i;
            dist[v] = dist[u] + 1;
            q.push(v);
          }
          else if (check[v] == i) {
            ans = max(ans, dist[u] - dist[v] + 1);
            break;
          }
        }
        // debug(i,check);
      }
        return ans;
    }
};