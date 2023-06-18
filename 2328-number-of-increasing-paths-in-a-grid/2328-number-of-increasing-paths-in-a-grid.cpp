using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using ti3 = tuple<ll,ll,ll>;

const ll mod = 1e9+7;
vi dr = {0,1,0,-1};
vi dc = {1,0,-1,0};

class Solution {
public:
    int countPaths(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        vvi dp(n, vi(m,1));
        vector<ti3> b;
        
        for (int i=0; i<n; i++) {
          for (int j=0; j<m; j++) {
            b.emplace_back(a[i][j],i,j);
          }
        }
        sort(b.begin(),b.end());
        
        for (auto [x,r,c] : b) {
          for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr<0 || nr>=n) continue;
            if (nc<0 || nc>=m) continue;
            if (a[nr][nc] > x) {
              dp[nr][nc] += dp[r][c];
              dp[nr][nc] %= mod;
            }
          }
        }
        
        ll ans = 0;
        
        for (int i=0; i<n; i++) {
          for (int j=0; j<m; j++) {
            ans += dp[i][j];
            ans %= mod;
          }
        }
        
        return ans;
    }
};