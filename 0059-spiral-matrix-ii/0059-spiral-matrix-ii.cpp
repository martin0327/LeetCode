using vi = vector<int>;
using vvi = vector<vi>;
vi dr = {0,1,0,-1}, dc = {1,0,-1,0};
const int inf = 1e9;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vvi ret(n, vi(n,inf));
        int r=0, c=0, d=0, v=1;
        while (v <= n*n) {
            ret[r][c] = v++;
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr*nc<0 || nr>=n || nc>=n || ret[nr][nc] != inf) {
                d = (d+1)%4;
                r = r + dr[d], c = c + dc[d];
            }
            else r = nr, c = nc;
        }
        return ret;
    }
};

