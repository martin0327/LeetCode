using ll = long long;
class Solution {
public:
  long long minimumTime(vector<int>& a, int k) {
    ll lo = 1, hi = 1e18, ans = -1;
    while (lo <= hi) {
      ll mid = (lo+hi)/2;
      ll cnt = 0;
      for (auto x : a) {
        cnt += mid / x;
        if (cnt >= k) break;
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