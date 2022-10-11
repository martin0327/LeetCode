class Solution {
public:
  bool increasingTriplet(vector<int>& a) {
    map<int,int> pre, suf;
    for (auto &x : a) suf[x]++;
    for (auto &x : a) {
      if (--suf[x] == 0) suf.erase(x);
      if (pre.lower_bound(x) != pre.begin()) {
        if (suf.upper_bound(x) != suf.end()) return true;
      }
      pre[x]++;
    }
    return false;
  }
};