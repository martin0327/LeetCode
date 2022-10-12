class Solution {
public:
  int largestPerimeter(vector<int>& a) {
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i=0; i+2 < a.size(); i++) {
      if (a[i] < a[i+1] + a[i+2]) {
        ans = max(ans, a[i]+a[i+1]+a[i+2]);
        break;
      }
    }
    return ans;
  }
};