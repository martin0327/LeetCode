class Solution {
public:
  vector<int> movesToStamp(string s, string t) {
    int n = t.size();
    int m = s.size();

    string z;
    for (int i=0; i<m; i++) z += '?';

    vector<int> ans;

    while (true) {
      int idx = -1;
      for (int i=0; i+m-1<n; i++) {
        string u = t.substr(i,m);
        if (u==z) continue;
        for (int j=0; j<m; j++) {
          if (u[j] == '?') u[j] = s[j];
        }
        if (u==s) {
          idx = i;
          for (int j=0; j<m; j++) {
            t[i+j] = '?';
          }
          break;
        }
      }
      if (idx == -1) break;
      else ans.push_back(idx);
    }
    bool ok = true;
    for (auto c : t) ok &= (c=='?');
    if (ok) {
      reverse(ans.begin(), ans.end());
      return ans;  
    }
    else {
      ans.clear();
      return ans;
    }
  }
};