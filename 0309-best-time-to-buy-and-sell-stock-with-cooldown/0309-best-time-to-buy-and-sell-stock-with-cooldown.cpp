using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vp = vector<pii>;
class Solution {
public:
    int maxProfit(vector<int>& a) {
          int n = a.size();

  vvi b(n, vi(n));
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      b[i][j] = max(b[i][j-1], a[j] - a[i]);
    }
  }

        
          vi c(n);
  for (int j=1; j<n; j++) {
    for (int i=0; i<j; i++) {
      c[j] = max(c[j], b[i][j]);
    }
    for (int i=0; i<j-1; i++) {
      c[j] = max(c[j], c[i] + b[i+2][j]);
    }
  }
  int ans = c[n-1];
        return ans;
    }
};

