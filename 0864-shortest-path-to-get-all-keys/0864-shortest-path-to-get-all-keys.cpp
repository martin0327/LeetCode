using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 1e9;
vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& a) {
        int k = 0, sr, sc, n = a.size(), m = a[0].size();
        vector<int> mp(26);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                char c = a[i][j];
                if ('a' <= c && c <= 'z') mp[c-'a'] = k++;
                if (c == '@') {
                    sr = i;
                    sc = j;
                }
            }
        }
        vector dist(n, vvi(m, vi(1<<k,inf)));
        dist[sr][sc][0] = 0;
        queue<tuple<ll,ll,ll>> q;
        q.push({sr,sc,0});
        while (q.size()) {
            auto [r,c,mask] = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                ll nr = r + dr[i];
                ll nc = c + dc[i];
                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                if (a[nr][nc] == '#') continue;
                char x = a[nr][nc];
                if ('A'<=x && x<='Z') {
                    if (!((mask>>(mp[x-'A']))&1)) continue;
                }
                
                ll nmask = mask;
                if ('a' <= x && x <= 'z') {
                    nmask |= (1<<(mp[x-'a']));
                }
                
                if (dist[nr][nc][nmask] > dist[r][c][mask] + 1) {
                    dist[nr][nc][nmask] = dist[r][c][mask] + 1;
                    q.emplace(nr,nc,nmask);
                }
            }
        }
        ll ans = inf;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ans = min(ans, dist[i][j][(1<<k)-1]);
            }
        }
        if (ans==inf) ans = -1;
        return ans;
    }
};