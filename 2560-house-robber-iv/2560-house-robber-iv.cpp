
class Solution {
public:
  int minCapability(vector<int>& a, int k) {
    int n = a.size(), lo = 1, hi = 1e9, ans = -1;
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      int cnt = 0, last = -2;
      for (int i=0; i<n; i++) {
        if (a[i] <= mid && i - last > 1) {
          cnt++;
          last = i;
        }
      }
      if (cnt >= k) {
        ans = mid;
        hi = mid - 1;
      }
      else lo = mid + 1;      
    }
    return ans;
  }
};