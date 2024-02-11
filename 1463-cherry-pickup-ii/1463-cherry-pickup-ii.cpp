class Solution {
public:
    template<int D, typename T>
    
    struct Vec : public vector<Vec<D - 1, T>> {
      static_assert(D >= 1, "Vector dimension must be greater than zero!");
      template<typename... Args>
      Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
      }
    };

    template<typename T>
    struct Vec<1, T> : public vector<T> {
      Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
      }
    };

  
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    int n,m;
    Vec<3,int> dp;
    vi dc = {-1,0,1};
    vvi grid;
  
    int f(int i, int j, int k) {
      if (dp[i][j][k] != -1) return dp[i][j][k];

      int ret = grid[i][j] + grid[i][k];
      // debug(i,j,k);
      // debug(ret);
      if (j==k) ret -= grid[i][j];
      if (i==n-1) return dp[i][j][k] = ret;

      int temp = 0;
      for (auto dj : dc) {
        for (auto dk : dc) {
          int nj = j + dj;
          int nk = k + dk;
          if (nj < 0 || nj >= m) continue;
          if (nk < 0 || nk >= m) continue;
          temp = max(temp, f(i+1,nj,nk));
        }
      }
      ret += temp;
      return dp[i][j][k] = ret;
    }
  
    int cherryPickup(vector<vector<int>>& a) {
      grid = a;      
      n = grid.size();
      m = grid[0].size();
      Vec<3,int> tempdp(n,m,m,-1);
      dp = tempdp;
      int ans = f(0,0,m-1);
      return ans;
    }
};