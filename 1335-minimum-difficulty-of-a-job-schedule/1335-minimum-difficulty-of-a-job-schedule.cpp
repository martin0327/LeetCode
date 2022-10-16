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

template<typename T>
T spt_min(T x, T y) {return min(x,y);}

template<typename T>
T spt_max(T x, T y) {return max(x,y);}

template<typename T,  T (*op)(T, T)>
struct sparse_table {
  int n,m;
  vector<vector<T>> table;

  inline T merge(T x, T y) {
    return op(x, y);
  }

  sparse_table(vector<T> &a) {
    n = a.size();
    m = __lg(n) + 1;
    table.assign(m, vector<T>(n));
    for (int i = 0; i < n; i++) table[0][i] = a[i];
    for (int i = 1; i < m; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        table[i][j] = merge(table[i-1][j], table[i-1][j + (1 << (i-1))]);
      }
    }
  }

  T query(int l, int r, const int index = 0) {
    // l, r : inclusive
    assert(l <= r && 0 <= l && r < n);
    int u = __lg(r-l+1);
    return merge(table[u][l-index], table[u][r-index-(1 << u)+1]);
  }
};

template<typename T>
using min_spt = sparse_table<T,spt_min>;

template<typename T>
using max_spt = sparse_table<T,spt_max>;

template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

const int inf = 1e9;

class Solution {
public:
  int minDifficulty(vector<int>& a, int d) {
    int n = a.size();
    max_spt<int> spt(a);

    Vec<3,int> dp(n+1,n+1,d+1,inf);
    dp[0][0][0] = 0;

    for (int i=0; i<n; i++) {
      for (int j=0; j<=n; j++) {
        for (int k=0; k<=d; k++) {
          int lo = max(0, i-j);
          if (k+1 <= d) {
            chmin(dp[i+1][0][k+1], dp[i][j][k] + spt.query(lo,i));
          } 
          if (j+1 <= n) chmin(dp[i+1][j+1][k], dp[i][j][k]);
        }
      }
    }
    int ans = dp[n][0][d];
    if (ans == inf) ans = -1;
    return ans;
  }
};