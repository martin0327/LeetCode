class Solution {
public:
    vector<bool> visited;
    int n;
    vector<int> nb = {-1,1};
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        visited.resize(n);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        if (arr[start] == 0) return true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto d : nb) {
                int v = u + d*arr[u];
                if (v<0 || v>=n) continue;
                if (visited[v]) continue;
                if (arr[v]==0) return true;
                q.push(v);
                visited[v] = true;
            }
        }
        return false;
    }
};