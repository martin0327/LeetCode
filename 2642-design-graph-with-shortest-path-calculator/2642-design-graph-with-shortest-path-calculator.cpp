using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 1e18;

class Graph {
public:
    ll n;
    vvi dist;
    vvi adj;
    
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        dist = vvi(n, vi(n,inf));
        for (int i=0; i<n; i++) dist[i][i] = 0;
        for (auto e : edges) {
            ll u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
        }
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }        
    }
    
    void addEdge(vector<int> e) {
        ll u = e[0], v = e[1], w = e[2];
        dist[u][v] = min(dist[u][v], w);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][v] + dist[v][j]);
            }
        }
    }
    
    int shortestPath(int u, int v) {
        return (dist[u][v] == inf) ? -1 : dist[u][v];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */