class Solution {
public:
  int largestPerimeter(vector<int>& a) {
    sort(a.rbegin(), a.rend());
    for (int i=0; i+2 < a.size(); i++) {
      if (a[i] < a[i+1] + a[i+2]) {
        return a[i]+a[i+1]+a[i+2];
      }
    }
    return 0;
  }
};   