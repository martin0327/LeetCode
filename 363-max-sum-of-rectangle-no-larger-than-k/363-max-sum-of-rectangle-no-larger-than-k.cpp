const int inf = 2e9;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int K) {
        int n = a.size();
        int m = a[0].size();
        vvi b(n+1, vi(m+1));
        for (int i=0; i<n; i++) {
          for(int j=0; j<m; j++) {
              b[i+1][j+1] = a[i][j];
          }
        }

        vvi pre(n+1, vi(m+1));
        for (int i=1; i<=n; i++) {
          for (int j=1; j<=m; j++) {
              pre[i][j] = pre[i-1][j] + b[i][j];
          }
        }

        // debug(pre);
        int ans = -inf;
        for (int i=0; i<n; i++) {
          for (int j=i+1; j<=n; j++) {
              vi c(m+1), pre2(m+1);
              for (int k=1; k<=m; k++) {
                  c[k] = pre[j][k] - pre[i][k];
              }
              for (int k=1; k<=m; k++) {
                  pre2[k] = pre2[k-1] + c[k];
              }
              set<int> s;
              for (int k=0; k<=m; k++) {
                  int x = pre2[k];
                  auto it = s.lower_bound(x-K);
                  if (it != s.end()) {
                    ans = max(ans, x - *it);
                  }
                  s.insert(x);
              }
          }
        }
        return ans;
    }
};