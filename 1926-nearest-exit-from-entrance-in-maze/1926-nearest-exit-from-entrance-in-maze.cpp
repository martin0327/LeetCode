using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

const int inf = 1e9;

class Solution {
public:
    vi dr = {0,-1,0,1};
    vi dc = {1,0,-1,0};
    
    int nearestExit(vector<vector<char>>& a, vector<int>& b) {
        int n = a.size();
        int m = a[0].size();
        int sr = b[0];
        int sc = b[1];
        
        vvi dist(n, vi(m, inf));
        dist[sr][sc] = 0;
        queue<pii> q;
        q.emplace(sr,sc);
        
        while (q.size()) {
            auto [r,c] = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                if (a[nr][nc] == '+') continue;
                if (dist[nr][nc] != inf) continue;
                dist[nr][nc] = dist[r][c] + 1;
                if (nr==0 || nr==n-1) return dist[nr][nc];
                if (nc==0 || nc==m-1) return dist[nr][nc];
                q.emplace(nr,nc);
            }
        }
        return -1;
    }
};