class Solution {
public:
  vector<string> twoEditWords(vector<string>& qr, vector<string>& dic) {
    int n = qr.size();
    int m = qr[0].size();
    vector<string> ans;
    for (auto s : qr) {
      bool found = false;
      for (auto t : dic) {
        int cnt = 0;
        for (int i=0; i<m; i++) {
          if (s[i] != t[i]) cnt++;
        }
        if (cnt<=2) found = true;
      }
      if (found) ans.push_back(s);
    }
  return ans;
  }
};