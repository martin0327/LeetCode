class Solution {
public:
  bool increasingTriplet(vector<int>& a) {
    map<int,int> pre, suf;
    for (auto x : a) suf[x]++;
    for (auto x : a) {
      if (--suf[x] == 0) suf.erase(x);
      auto it1 = pre.lower_bound(x);
      auto it2 = suf.upper_bound(x);
      if (it1 != pre.begin() && it2 != suf.end()) {
        return true;
      }
      pre[x]++;
    }
    return false;
  }
};