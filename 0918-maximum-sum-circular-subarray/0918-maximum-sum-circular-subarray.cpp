template<typename T> void chmax(T &x, T y) {x = max(x,y);}
template<typename T> void chmin(T &x, T y) {x = min(x,y);}
using vi = vector<int>;

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& a) {
    int n = a.size();
    vi pre(n+2), suf(n+2);
    for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
    for (int i=n; i>=1; i--) suf[i] = suf[i+1] + a[i-1];

    vi premin = pre, sufmax = suf;
    for (int i=1; i<=n; i++) chmin(premin[i],premin[i-1]);
    for (int i=n; i>=1; i--) chmax(sufmax[i],sufmax[i+1]);

    int ans = -1e9;
    for (int i=1; i<=n; i++) {
      int x = pre[i] - premin[i-1];
      int y = pre[i] + sufmax[i+1];
      chmax(ans, max(x,y));
    }
    return ans;
  }
};