class Solution {
public:
  int minEatingSpeed(vector<int>& a, int h) {
    int lo = 1, hi = 1e9, ans = -1;
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      long long cnt = 0;
      for (auto x : a) cnt += (x+mid-1)/mid;
      if (cnt <= h) {
        ans = mid;
        hi = mid - 1;
      }
      else lo = mid + 1;
    }
    return ans;
  }
};