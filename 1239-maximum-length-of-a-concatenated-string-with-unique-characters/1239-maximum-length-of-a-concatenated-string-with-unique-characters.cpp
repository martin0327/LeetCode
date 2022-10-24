class Solution {
public:
  int maxLength(vector<string>& a) {
    int n = a.size();
    int ret = 0;
    for (int mask=0; mask<(1<<n); mask++) {
      int cnt = 0;
      bool ok = true;
      int s = 0;
      for (int i=0; i<n; i++) {
        if (!ok) break;
        if (mask>>i&1) {
          for (auto c : a[i]) {
            int x = c-'a';
            if (cnt>>x&1) {
              ok = false;
              break;
            }
            else cnt |= 1<<x;
          }
          s += a[i].size();
        }
      }      
      if (ok) ret = max(ret, s);
    }
    return ret;
  }
};