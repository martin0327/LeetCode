using ll = long long;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& a) {
      int m = a.size();
      sort(a.begin(), a.end());
      ll s = 0;
      for (int i=0; i<m-n; i++) s += a[i];
      vector<ll> b;
      for (int i=m-n; i<m; i++) b.push_back(a[i]);

      ll prev = b[0];
      ll ans = b[0];
      for (int i=1; i<n; i++) {
        int d = b[i] - prev;
        if (s >= d*i) {
          ans += d;
          s -= d*i;
        }
        else {
          ans += s / i;
          s %= i;
          break;
        }
        prev = b[i];
      }  
      ans += s / n;
      return ans;
        
    }
};