using ll = long long;
using vi = vector<ll>;

class Solution {
public:
  long long countSubarrays(vector<int>& a, int minK, int maxK) {

    ll n = a.size(), ans = 0;
    set<ll> mn, mx, blk; 
    if (minK > maxK) return 0;
    else if (minK == maxK) {
      mx = blk = {n};
      for (int i=0; i<n; i++) {
        if (a[i]==maxK) mx.insert(i);
        else if (a[i] < minK || a[i] > maxK) blk.insert(i);
      }
      for (int i=0; i<n; i++) {
        if (blk.count(i)) continue;
        if (a[i] == maxK) ans += *blk.upper_bound(i) - i;
        else {
          ll r = *mx.upper_bound(i);
          ll lim = *blk.upper_bound(i);
          if (r < lim) ans += lim - r;
        }
      }
    }
    else {
      mn = mx = blk = {n};
      for (int i=0; i<n; i++) {
        if (a[i] == minK) mn.insert(i);
        else if (a[i] == maxK) mx.insert(i);
        else if (a[i] < minK || a[i] > maxK) blk.insert(i); 
      }

      for (int i=0; i<n; i++) {
        if (blk.count(i)) continue;
        if (a[i] == minK) {
          ll r = *mx.upper_bound(i);
          ll lim = *blk.upper_bound(i);
          if (r < lim) ans += lim - r;
        }
        else if (a[i] == maxK) {
          ll r = *mn.upper_bound(i);
          ll lim = *blk.upper_bound(i);
          if (r < lim) ans += lim - r;
        }
        else {
          ll l = *mn.upper_bound(i);
          ll r = *mx.upper_bound(i);
          if (l > r) swap(l,r);
          ll lim = *blk.upper_bound(i);
          if (r < lim) ans += lim - r;
        }
      }
    }
    return ans;

  }
};