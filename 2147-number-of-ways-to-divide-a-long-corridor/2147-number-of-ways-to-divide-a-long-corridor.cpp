using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int numberOfWays(string s) {
      int n = s.size();

      int cnt = 0;
      for (auto c : s) if (c=='S') cnt++;

      if (cnt&1 || !cnt) return 0;

      cnt = 0;
      int r = -1;

      ll ans = 1;
      for (int i=0; i<n; i++) {
        if (s[i] == 'S') {
          if (cnt==0) {
            cnt++;
            if (r == -1) continue;
            ans *= (i-r);
            ans %= mod;
          }
          else {
            r = i;
            cnt = 0;
          }
        }
      }
      
      return ans;
    }
};