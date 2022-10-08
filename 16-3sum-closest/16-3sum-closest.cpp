const int inf = 2e9;

class Solution {
public:
  int threeSumClosest(vector<int>& a, int t) {
    int n = a.size();
    sort(a.begin(), a.end());

    int ans = 0, diff = inf;
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        int x = a[i] + a[j];
        auto it = lower_bound(a.begin()+j+1, a.end(), t-x);
        if (it != a.end()) {
          int y = *it;
          if (abs(x+y-t) < diff) {
            diff = abs(x+y-t);
            ans = x+y;
          }
        }
        if (it != a.begin()+j+1) {
          int y = *prev(it);
          if (abs(x+y-t) < diff) {
            diff = abs(x+y-t);
            ans = x+y;
          }
        }
      }
    }
    return ans;
  }
};       