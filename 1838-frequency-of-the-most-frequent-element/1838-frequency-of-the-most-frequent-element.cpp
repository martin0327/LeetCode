using ll = long long;
using vi = vector<ll>;

class Solution {
public:
  int maxFrequency(vector<int>& a, int k) {
    
    ll n = a.size();
    sort(a.begin(), a.end());
    a.insert(a.begin(), 0);

    vi pre(n+1); 
    for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
    ll ans = 1;

    for (ll i=1; i<=n; i++) {
      ll x = a[i];
      ll lo = 0; 
      ll hi = i;
      ll idx = -1;
      while (lo <= hi) {
        ll mid = (lo+hi)/2;
        ll cnt = i - mid;
        ll s = pre[i] - pre[mid];
        if (cnt*x - s <= k) {
          idx = mid;
          hi = mid - 1;
        }      
        else lo = mid + 1;
      }
      if (idx != -1) ans = max(ans, i-idx);
    }
    return ans;
  }
};