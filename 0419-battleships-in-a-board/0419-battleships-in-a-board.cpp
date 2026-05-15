using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int countBattleships(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;
        vvi vis(n, vi(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '.') continue;
                if (!vis[i][j]) {
                    ans++;
                    vis[i][j] = 1;
                    for (int c=j+1; c<m; c++) {
                        if (a[i][c] == 'X' && !vis[i][c]) {
                            vis[i][c] = 1;
                        }
                        else break;
                    }
                    for (int r=i+1; r<n; r++) {
                        if (a[r][j] == 'X' && !vis[r][j]) {
                            vis[r][j] = 1;
                        }
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};