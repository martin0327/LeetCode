template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using ti5 = tuple<ll,ll,ll,ll,ll>;

vi dr = {0,1,0,-1};
vi dc = {1,0,-1,0};
const ll inf = 0x3f3f3f3f3f3f3f3f; 
const int sz = 80;
ll dist[sz][sz][sz][5];

class Solution {
public:
    int minCost(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0][0][0] = dist[0][0][0][1] = a[0][0];
        min_pq<ti5> pq;
        pq.push({a[0][0],0,0,0,0});
        pq.push({a[0][0],0,0,0,1});
        auto oob = [&] (int r, int c) {
            if (r < 0 || r >= n) return true;
            if (c < 0 || c >= m) return true;
            return false;
        };
        while (pq.size()) {
            auto [d,r,c,t,dir] = pq.top();
            pq.pop();
            if (d > dist[r][c][t][dir]) continue;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (oob(nr,nc)) continue;
                int nd = d + a[nr][nc];
                int ndir = i;
                int nt = t + (ndir != dir);
                if (nt > k) continue;
                if (nd < dist[nr][nc][nt][ndir]) {
                    dist[nr][nc][nt][ndir] = nd;
                    pq.push({nd,nr,nc,nt,ndir});
                }
            }
        }
        auto ans = inf;
        for (int i=0; i<=k; i++) {
            for (int j=0; j<4; j++) {
                chmin(ans, dist[n-1][m-1][i][j]);
            }
        }
        if (ans == inf) ans = -1;
        return ans;
    }
};
