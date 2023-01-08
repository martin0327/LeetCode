using pii = pair<int,int>;
using vp = vector<pii>;


class Solution {
public:
  
  int f(pii p1, pii p2, pii p3) {
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    auto [x3,y3] = p3;
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
  }
  
  int maxPoints(vector<vector<int>>& points) {

    int n = points.size();
    vp a;
    for (auto p : points) a.emplace_back(p[0],p[1]);
    
    int ans = 1;
    for (int i=0; i<n; i++) {
      pii x = a[i];
      for (int j=i+1; j<n; j++) {
        pii y = a[j];
        int temp = 0;
        for (int k=j+1; k<n; k++) {
          pii z = a[k];
          if (f(x,y,z) == 0) temp++;
        }
        ans = max(ans, temp+2);
      }
    }
    return ans;
  }
};