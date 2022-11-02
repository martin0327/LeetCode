class Solution {
public:
  int minMutation(string start, string end, vector<string>& b) {
    map<string,int> dist;
    dist[start] = 0;
    queue<string> q;
    q.push(start);
    while (q.size()) {
      auto u = q.front(); q.pop();
      for (auto v : b) {
        if (dist.count(v)) continue;
        int cnt = 0;
        for (int i=0; i<8; i++) {
          if (u[i] != v[i]) cnt++;
        }
        if (cnt==1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    if (dist.count(end)) return dist[end];
    else return -1;
  }
}; 