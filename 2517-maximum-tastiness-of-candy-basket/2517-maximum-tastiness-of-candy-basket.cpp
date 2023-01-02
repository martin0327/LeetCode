using ll = long long;
class Solution {
public:
  int maximumTastiness(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    ll lo = 0, hi = 1e9;
    ll ans = -1;
    while (lo <= hi) {
      ll mid = (lo+hi)/2;
      ll cur = a[0], cnt = 1;
      for (int i=1; i<n; i++) {
        if (a[i] - cur >= mid) {
          cnt++;
          cur = a[i];
        }
      }  
      if (cnt >= k) {
        ans = mid;
        lo = mid + 1;
      }
      else hi = mid - 1;
    }
    return ans;
  }
};