template<typename T>
struct max_spt {
  int n,m;
  vector<vector<T>> table;

  inline T merge(T x, T y) {
    return max(x,y);
  }

  max_spt(vector<T> &a) {
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
    if (l < 0) l = 0;
    if (r >= n) r = n-1;
    if (l <= r) {
      int u = __lg(r-l+1);
      return merge(table[u][l-index], table[u][r-index-(1 << u)+1]);
    }
    else return 0;
  }
};

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& a, int k) {
    using ll = long long;
    using vi = vector<ll>;
    using vvi = vector<vi>;

    int n = a.size();
    const int inf = 1e9;
    vector<ll> b(a.begin(), a.end());
    max_spt<ll> spt(b);
    vvi dp(n+1, vi(k+1,-inf));
    dp[0][0] = 0;
    auto chmax = [&](ll &x, ll y) {x = max(x,y);};
    for (int i=0; i<n; i++) {
      for (int j=0; j<=k; j++) {
        if (j < k) {
          if (spt.query(i-j,i-1) >= a[i]) chmax(dp[i+1][j+1], dp[i][j] + spt.query(i-j,i-1));      
          else chmax(dp[i+1][j+1], dp[i][j] - j*spt.query(i-j,i-1) + (j+1)*a[i]);
        }
        chmax(dp[i+1][1],dp[i][j] + a[i]);
      }
    }
    return *max_element(dp[n].begin(), dp[n].end());
  }
};