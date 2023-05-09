vector<int> dr = {0,1,0,-1}, dc = {1,0,-1,0};
const int inf = 1e9;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ret;
        int n = a.size(), m = a[0].size(), r=0, c=0, d=0;
        while (ret.size() < n*m) {
            ret.push_back(a[r][c]);
            a[r][c] = inf;
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr*nc < 0 || nr >=n || nc >= m || a[nr][nc] == inf) {
                d = (d+1)%4;
                r = r + dr[d], c = c + dc[d];
            }
            else r = nr, c = nc;
        }
        return ret;
    }
};