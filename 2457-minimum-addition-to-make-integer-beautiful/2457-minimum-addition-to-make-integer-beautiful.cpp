using ll = long long;
class Solution {
public:
  long long makeIntegerBeautiful(long long n, int target) {
    string s = to_string(n);
    ll tot = 0;
    for (auto c : s) tot += (c-'0');
    if (tot <= target) {
      return 0;
    }

    ll mod = 10;
    ll ans = 1e15;
    while (mod <= 1e15) {
      ll x = mod - (n % mod);
      ll y = n + x;
      string s = to_string(y);
      ll tot = 0;
      for (auto c : s) tot += (c - '0');
      if (tot <= target) {
        ans = min(ans, x);
        break;
      }
      mod *= 10;
    }
    return ans;
  }
};