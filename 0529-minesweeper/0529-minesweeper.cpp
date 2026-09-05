using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
const int sz = 51;
bool vis[sz][sz];
vi dr,dc;
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& a, vector<int>& src) {
        int n = a.size(), m = a[0].size();
        memset(vis, 0, sizeof(vis));
        if (dr.empty()) {
            for (int r=-1; r<=1; r++) {
                for (int c=-1; c<=1; c++) {
                    if (r==0 && c==0) continue;
                    dr.push_back(r);
                    dc.push_back(c);
                }
            }
        }

        auto sr = src[0], sc = src[1];
        if (a[sr][sc] == 'M') {
            a[sr][sc] = 'X';
            return a;
        }

        auto oob = [&] (int r, int c) {
            if (r < 0 || r >= n) return true;
            if (c < 0 || c >= m) return true;
            return false;
        };

        queue<pii> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        vp nb;
        while (q.size()) {
            auto [r,c] = q.front();
            q.pop();
            nb.clear();
            int cnt = 0;
            for (int i=0; i<8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (oob(nr,nc)) continue; 
                if (a[nr][nc] == 'M') cnt++;
                else if (a[nr][nc] == 'E') {
                    if (!vis[nr][nc]) {
                        nb.push_back({nr,nc});
                    }
                }
            }
            if (cnt == 0) {
                a[r][c] = 'B';
                for (auto [nr,nc] : nb) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
            else {
                a[r][c] = '0' + cnt;
            }
        }
        return a;
    }
};