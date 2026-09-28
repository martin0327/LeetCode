using vi = vector<int>;
using vvi = vector<vi>;
vi dr = {0,1}, dc = {1,0};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int c2) {
        int n = a.size(), m = a[0].size();
        vvi b(n, vi(m));
        b[sr][sc] = 1;
        int c1 = a[sr][sc];
        a[sr][sc] = c2;
        while (true) {
            bool done = true;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    for (int d=0; d<2; d++) {
                        int r = i + dr[d];
                        int c = j + dc[d];
                        if (r >= n || c >= m) continue;
                        if (b[i][j] ^ b[r][c]) {
                            if (b[i][j]) {
                                if (a[r][c] == c1) {
                                    a[r][c] = c2;
                                    b[r][c] = 1;
                                    done = false;
                                }
                            }
                            else {
                                if (a[i][j] == c1) {
                                    a[i][j] = c2;
                                    b[i][j] = 1;
                                    done = false;
                                }
                            }
                        }
                    }
                }
            }
            if (done) break;
        }
        return a;
    }
};