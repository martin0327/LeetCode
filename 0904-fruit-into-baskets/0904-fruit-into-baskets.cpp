class Solution {
public:
  int totalFruit(vector<int>& a) {
    int n = a.size();
    vector<int> b(n);
    int i=0, j=0, cnt=0, ans=0;
    while (i<n) {
      if (cnt<=2 && j<n) {
        if (!b[a[j++]]++) cnt++;
      }
      else if (!--b[a[i++]]) cnt--;
      if (cnt<=2) ans = max(ans, j-i);
    }
    return ans;
  }
};