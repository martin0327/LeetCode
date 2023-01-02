class Solution {
public:
  int closetTarget(vector<string>& a, string t, int j) {
    int ret = 1e9;
    int n = a.size();
    for (int i=0; i<n; i++) {
      if (a[i] == t) {
        ret = min(ret, abs(i-j));
        ret = min(ret, abs(i+n-j));
        ret = min(ret, abs(i-n-j));
      }
    }    
    if (ret == 1e9) ret = -1;
    return ret;
  }
};