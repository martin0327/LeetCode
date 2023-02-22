class Solution {
public:
  int shipWithinDays(vector<int>& a, int d) {
    int ans = -1, lo = *max_element(a.begin(), a.end()), hi = 25e6;
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      int cnt = 1, cur = 0;
      for (auto x : a) {
        cur += x;
        if (cur > mid) {
          cur = x;
          cnt++;
        }
      }
      if (cnt <= d) {
        ans = mid;
        hi = mid - 1;
      }
      else lo = mid + 1;
    }
    return ans;
  }
};