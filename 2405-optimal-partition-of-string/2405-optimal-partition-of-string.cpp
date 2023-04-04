class Solution {
public:
  int partitionString(string s) {
    vector<int> cnt(26);
    int ans = 0;
    for (auto c : s) {
      int x = c - 'a';
      if (cnt[x] == 1) {
        ans++;
        cnt.assign(26, 0);
      }
      cnt[x]++;
    }
    ans++;
    return ans;
  }
};