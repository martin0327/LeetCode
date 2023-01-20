using ll = long long;
class Solution {
public:
  long long countGood(vector<int>& a, int k) {
    ll n = a.size();
    ll i = 0, j = 0;
    map<ll,ll> mp;
    ll cnt = 0;
    ll ans = 0;
    while (i<n) {
      if (cnt < k && j < n) cnt += mp[a[j++]]++;
      else cnt -= --mp[a[i++]];
      if (cnt >= k) ans += n - j + 1;
    }
    return ans;
  }
};