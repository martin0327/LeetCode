using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  string orderlyQueue(string s, int k) {
    int n = s.size();
    if (k>1) {
      sort(s.begin(), s.end());
      return s;
    }
    
    string ans = s;
    for (int i=0; i<n; i++) {
      s += s.front();
      s = s.substr(1, s.size()-1);
      ans = min(ans, s);
    }
    return ans;
  }
};  