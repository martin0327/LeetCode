using vi = vector<int>;
const int inf = 1e9;
class Solution {
public:
    int numSquares(int n) {
        vi dist(n+1, inf);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (int i=1; i*i<=n; i++) {
                int v = u + i*i;
                if (v > n) break;
                if (dist[v] != inf) continue;
                dist[v] = dist[u] + 1;
                if (v==n) return dist[v];
                q.push(v);
            }
        }
        return dist[n];
    }
};