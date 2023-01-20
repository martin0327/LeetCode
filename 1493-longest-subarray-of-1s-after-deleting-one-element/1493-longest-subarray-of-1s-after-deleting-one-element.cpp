using vi = vector<int>;
class Solution {
public:
  int longestSubarray(vector<int>& a) {
    int n = a.size();
    a.insert(a.begin(), 0);
    a.push_back(0);
    vi pre = a, suf = a;
    for (int i=1; i<=n; i++) {
      if (pre[i]) pre[i] += pre[i-1];
    }
    for (int i=n; i>=1; i--) {
      if (suf[i]) suf[i] += suf[i+1];
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
      ans = max(ans, pre[i-1] + suf[i+1]);
    }
    return ans;
  }
};