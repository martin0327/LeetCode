using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    
    int minJumps(vector<int>& a) {
        
        int n = a.size();
        map<int,vi> mp;
        for (int i=0; i<n; i++) {
            mp[a[i]].push_back(i);
        }
        
        vi dist(n, -1);
        queue<int> q;
        set<int> check;
        
        q.push(0);
        dist[0] = 0;
        
        while (q.size()) {
            int u = q.front();
            q.pop();
            
            for (int i=-1; i<=1; i+=2) {
                int v = u + i;
                if (v < 0 || v >= n) continue;
                if (dist[v] != -1) continue;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
            if (check.count(a[u])) continue;
            
            for (auto v : mp[a[u]]) {
                if (dist[v] != -1) continue;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
            check.insert(a[u]);
            if (dist[n-1] != -1) return dist[n-1];
        }
        return dist[n-1];
    }
};