class Solution {
public:
    
    void debug(vector<int> &a) {
        for (auto x : a) {
            cout << x << " ";
        }   cout << endl;
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        int mx = max(x,y)+11;
        vector<int> vis(mx+1, -1);
        vis[x] = 0;
        queue<int> q;
        q.push(x);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i=5; i<=11; i+=6) {
                if (u % i == 0) {
                    int v = u / i;
                    if (vis[v] == -1) {
                        vis[v] = vis[u] + 1;
                        q.push(v);
                    }
                }
            }
            for (int i=-1; i<=1; i+=2) {
                int v = u + i;
                if (v < 0 || v > mx) continue;
                if (vis[v] == -1) {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
        return vis[y];
    }
};