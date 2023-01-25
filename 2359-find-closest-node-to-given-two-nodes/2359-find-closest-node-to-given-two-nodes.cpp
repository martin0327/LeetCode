class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
          using ll = long long;
          int inf = 1e9;
          vector<ll> dist1(n,inf), dist2(n,inf);

          queue<ll> q;
          q.push(node1);
          dist1[node1] = 0;
          while (q.size()) {
            int u = q.front();
            q.pop();
            int v = edges[u];
            if (v==-1) continue;
            if (dist1[v] == inf) {
              dist1[v] = dist1[u] + 1;
              q.push(v);
            }
          }
          q.push(node2);
          dist2[node2] = 0;
          while (q.size()) {
            int u = q.front();
            q.pop();
            int v = edges[u];
            if (v==-1) continue;
            if (dist2[v] == inf) {
              dist2[v] = dist2[u] + 1;
              q.push(v);
            }
          }
          ll ans = inf;
          ll idx = -1;
          for (int i=0; i<n; i++) {
            int temp = max(dist1[i],dist2[i]);
            if (temp < ans) {
              ans = temp;
              idx = i;
            }
          }
        
        return idx;
    }
};