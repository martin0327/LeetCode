using vi = vector<int>;
class Solution {
public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& qr) {
    vi ans;
    for (auto uv : qr) {
      int u = uv[0];
      int v = uv[1];

      vi a,b;
      for (int i=0; i<30; i++) {
        if (u>>i&1) a.push_back(1);
        else a.push_back(0);
        if (v>>i&1) b.push_back(1);
        else b.push_back(0);
      }
      
      while (a.size()) {
        if (a.back()) break;
        else a.pop_back();
      }
      while (b.size()) {
        if (b.back()) break;
        else b.pop_back();
      }
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      
      if (a.size() > b.size()) swap(a,b);
      int cnt = 0;
      while (a.size() < b.size()) {
        cnt++;
        b.pop_back();
      }
      while (a.size()) {
        if (a == b) break;
        else {
          a.pop_back();
          b.pop_back();
          cnt+=2;
        }
      }
      ans.push_back(cnt+1);
    }
    return ans;
  }
};