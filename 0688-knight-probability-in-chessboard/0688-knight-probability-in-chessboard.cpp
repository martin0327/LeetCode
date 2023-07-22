using vi = vector<int>;
using vd = vector<double>;
using vvd = vector<vd>;

class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        vvd dp1(n, vd(n));
        vvd dp2 = dp1;
        dp1[row][col] = 1;
        
        vi dr, dc;
        for (int i=-2; i<=2; i++) {
            for (int j=-2; j<=2; j++) {
                if (abs(i)+abs(j) != 3) continue;
                dr.push_back(i);
                dc.push_back(j);
            }
        }
        
        for (int t=0; t<k; t++) {
            for (int r=0; r<n; r++) {
                for (int c=0; c<n; c++) {
                    for (int d=0; d<dr.size(); d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr < 0 || nr >= n) continue;
                        if (nc < 0 || nc >= n) continue;
                        dp2[nr][nc] += dp1[r][c] / 8.0;
                    }
                }
            }
            dp1 = dp2;
            dp2 = vvd(n, vd(n));
        }
        double ans = 0;
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                ans += dp1[r][c];
            }
        }
        return ans;
    }
};