class Solution {
public:
  int subarrayLCM(vector<int>& a, int k) {
    int n = a.size();
    int ans = 0;
    for (int i=0; i<n; i++) {
      long long x = a[i];
      for (int j=i; j<n; j++) {
        x = lcm(x, a[j]);
        if (x > k) break;
        if (x==k) ans++;
      }
    }
    return ans;
  }
};