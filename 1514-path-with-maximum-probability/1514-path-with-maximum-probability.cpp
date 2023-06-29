class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int s, int t) {
        vector<vector<pair<int,int>>> adj(n);
        int m = edges.size();
        for (int i=0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        vector<double> dist(n);
        dist[s] = 1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,s});
        while (pq.size()) {
            auto [w,u] = pq.top();
            pq.pop();
            if (w != dist[u]) continue;
            for (auto [v,i] : adj[u]) {
                if (dist[v] < dist[u] * sp[i]) {
                    dist[v] = dist[u] * sp[i];
                    pq.push({dist[v],v});
                }
            }
        }
        double ans = dist[t];
        return ans;
    }
};