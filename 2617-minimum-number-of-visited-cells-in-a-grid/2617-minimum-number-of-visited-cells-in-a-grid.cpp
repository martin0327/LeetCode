using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
const int inf = 1e9;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<set<int>> vs(m), hs(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                vs[j].insert(i);
                hs[i].insert(j);
            }
        }
        queue<pii> q;
        vvi dist(n, vi(m,inf));
        q.emplace(0,0);
        dist[0][0] = 1;
        vs[0].erase(0);
        hs[0].erase(0);
        while (q.size()) {
            auto [r,c] = q.front(); q.pop();
            {
                int lo = r+1, hi = r+a[r][c];
                auto it = vs[c].lower_bound(lo);
                while (it != vs[c].end()) {
                    if (*it > hi) break;
                    int nr = *it, nc = c;
                    it++;
                    if (dist[nr][nc] < inf) continue;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.emplace(nr,nc);
                    vs[nc].erase(nr);
                    hs[nr].erase(nc);
                }
            }
            {
                int lo = c+1, hi = c+a[r][c];
                auto it = hs[r].lower_bound(lo);
                while (it != hs[r].end()) {
                    if (*it > hi) break;
                    int nr = r, nc = *it;
                    it++;
                    if (dist[nr][nc] < inf) continue;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.emplace(nr,nc);
                    vs[nc].erase(nr);
                    hs[nr].erase(nc);
                }
            }
        }
        int ans = dist[n-1][m-1];
        if (ans==inf) ans = -1;
        return ans;
    }
};