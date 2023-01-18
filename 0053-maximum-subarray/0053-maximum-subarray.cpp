using vi = vector<int>;
class Solution {
public:
  int maxSubArray(vector<int>& a) {
    int n = a.size();
    vi pre(n+1);
    for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
    vi premin = pre;
    for (int i=1; i<=n; i++) premin[i] = min(premin[i], premin[i-1]);
    int ans = -1e9;
    for (int i=1; i<=n; i++) ans = max(ans, pre[i] - premin[i-1]);
    return ans;
  }
};