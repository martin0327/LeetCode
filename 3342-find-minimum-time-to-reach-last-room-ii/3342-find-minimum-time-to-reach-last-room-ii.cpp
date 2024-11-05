using vi = vector<int>;
using vvi = vector<vi>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ti3 = tuple<int,int,int>;

const int inf = 2e9;
vi dr = {0,1,0,-1};
vi dc = {1,0,-1,0};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        min_pq<ti3> pq;
        pq.push({0,0,0});
        vvi dist(n, vi(m,inf));
        dist[0][0] = 0;
        while (pq.size()) {
            auto [w,r,c] = pq.top(); pq.pop();
            if (w > dist[r][c]) continue;

            for (int d=0; d<4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                int dt = ((nr+nc)&1)?1:2;
                int nw = max(w+dt,a[nr][nc]+dt);
                if (nw < dist[nr][nc]) {
                    pq.push({nw,nr,nc});
                    dist[nr][nc] = nw;
                }
            }
        }
        int ans = dist[n-1][m-1];
        return ans;
        
    }
};