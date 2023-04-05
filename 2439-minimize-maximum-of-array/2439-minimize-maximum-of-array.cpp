class Solution {
public:
  int minimizeArrayValue(vector<int>& a) {
    using ll = long long;
    int n = a.size();

    vector<ll> c(n);
    for (int i=0; i<n; i++) c[i] = a[i];

    ll lo = 0;
    ll hi = 1e9;

    ll ans = -1;
    while (lo <= hi) {
      ll mid = (lo+hi)/2;
      vector<ll> b = c;
      for (int i=n-1; i>0; i--) {
        if (b[i] > mid) {
          ll d = b[i] - mid;
          b[i] -= d;
          b[i-1] += d;
        }
      }
      if (b[0] <= mid) {
        ans = mid;
        hi = mid - 1;
      }
      else {
        lo = mid + 1;
      }
    }
    return ans;
  }
};