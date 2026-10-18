
using vi = vector<int>;
using vvi = vector<vi>;

vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};
map<char,int> c2i;
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vvi vis(n, vi(m));
        vis[0][0] = 1;
        if (c2i.empty()) {
            auto t = "LRUD";
            for (int i=0; i<4; i++) {
                c2i[t[i]] = i;
            }
        }
        int r = 0, c = 0;
        auto f = [&] (int r, int c) {
            if (r < 0 || r >= n) return true;
            if (c < 0 || c >= m) return true;
            return false;
        };
        vector<int> ans;
        while (true) {
            auto i = c2i[a[r][c]];
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (f(nr,nc) || vis[nr][nc]) {
                ans = {r,c};
                return ans;
            }
            vis[nr][nc] = 1;
            r = nr;
            c = nc;
        }
        return ans;
    }
};