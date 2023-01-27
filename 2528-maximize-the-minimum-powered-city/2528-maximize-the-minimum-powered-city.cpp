using ll = long long;

class Solution {
public:
  long long maxPower(vector<int>& a, int r, int k) {
    ll n = a.size(), lo = 0, hi = 2e10, ans = -1, ss = 0;
    for (int i=0; i<r; i++) ss += a[i];

    while (lo <= hi) {
      ll mid = (lo + hi) / 2;
      ll llim = 0, rlim = r-1;
      ll s = ss;
      ll cnt = 0;
      vector<ll> b(n);
      for (ll i=0; i<n; i++) {
        if (llim < i-r) {
          s -= a[llim];
          s -= b[llim++];
        }
        if (rlim < n-1) s += a[++rlim];
        
        ll d = max(0ll, mid - s);
        b[rlim] += d;
        s += d;
        cnt += d;
        if (cnt > k) break;
      }
      if (cnt <= k) {
        ans = mid;
        lo = mid + 1;
      }
      else hi = mid - 1;
    }

    return ans;
  }
};  