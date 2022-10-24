class Solution {
public:
  int maxLength(vector<string>& a) {
    int n = a.size();
    int ret = 0;
    for (int mask=0; mask < 1<<n; mask++) {
      vector<int> cnt(26);
      for (int i=0; i<n; i++) {
        if (mask>>i&1) {
          for (auto c : a[i]) {
            cnt[c - 'a']++;
          }
        }
      }
      bool ok = true;
      int s = 0;
      for (int i=0; i<26; i++) {
        if (cnt[i] > 1) ok = false;
        s += cnt[i];
      }
      if (ok) ret = max(ret, s);
    }
    return ret;
  }
};