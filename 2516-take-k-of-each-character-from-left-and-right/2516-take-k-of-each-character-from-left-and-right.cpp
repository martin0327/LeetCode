using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.size();
    vvi pre(n+1, vi(3));
    for (int i=0; i<n; i++) {
      pre[i+1] = pre[i];
      pre[i+1][s[i]-'a']++;
    }

    int ans = -1;
    int lo = 0, hi = n;
    while (lo <= hi) {
      int mid = (lo+hi) / 2;
      bool ok = false;
      for (int i=0; i<=mid; i++) {
        bool flag = true;
        for (int j=0; j<3; j++) {
          flag &= (pre[i][j] + pre[n][j] - pre[n-mid+i][j] >= k);
        }
        if (flag) {
          ok = true;
          break;
        }
      }
      if (ok) {
        ans = mid;
        hi = mid - 1;
      }
      else lo = mid + 1;
    }
    return ans;
  }
};