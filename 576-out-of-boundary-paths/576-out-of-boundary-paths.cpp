class Solution {
public:
    const int mod = 1e9+7;
    using ti3 = tuple<int,int,int>;
    using ll = long long;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    
    int findPaths(int n, int m, int maxMove, int sr, int sc) {
        ll a[n][m][maxMove+1];
        int check[n][m][maxMove+1];
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));
        
        queue<ti3> q;
        q.push({sr,sc,0});
        a[sr][sc][0] = 1;
        check[sr][sc][0] = 1;
        ll ans = 0;
        while (q.size()) {
            auto [r,c,d] = q.front();
            q.pop();
            if (d==maxMove) continue;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr<0 || nr>=n || nc<0 || nc>=m) {
                    ans += a[r][c][d];
                    ans %= mod;
                }
                else {
                    a[nr][nc][d+1] += a[r][c][d];
                    a[nr][nc][d+1] %= mod;
                    if (check[nr][nc][d+1]==0) {
                        check[nr][nc][d+1] = 1;
                        q.push({nr,nc,d+1});
                    }
                }
            }
        }
        return ans;
    }
};