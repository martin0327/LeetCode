using vi = vector<int>;
class Solution {
public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& qr) {
    vi ans;
    for (auto uv : qr) {
      int u = uv[0];
      int v = uv[1];

      if (u > v) swap(u,v);
      int x = 0, y = 0;
      {
        int t = u;
        while (t) {
          t >>= 1;
          x++;
        }
        
        t = v;
        while (t) {
          t >>= 1;
          y++;
        }
      }
      
      int cnt = y - x;
      while (y > x) {
        y--;
        v >>= 1;        
      }

      while (u) {
        if (u==v) break;
        else {
          u >>= 1;
          v >>= 1;
          cnt += 2;
        }
      }
      ans.push_back(cnt+1);
    }
    return ans;
  }
};