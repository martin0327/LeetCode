class Solution {
public:
  int maxLength(vector<string>& a) {
    int n = a.size();
    int ret = 0;
    for (int mask=0; mask<(1<<n); mask++) {
      vector<int> cnt(26);
      bool ok = true;
      int s = 0;
      for (int i=0; i<n; i++) {
        if (mask>>i&1) {
          for (auto c : a[i]) {
            if (cnt[c - 'a']++) ok = false;;
            s++;
          }
        }
      }      
      if (ok) ret = max(ret, s);
    }
    return ret;
  }
};