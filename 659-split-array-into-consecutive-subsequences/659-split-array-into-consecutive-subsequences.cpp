class Solution {
public:
  bool isPossible(vector<int>& a) {
    map<int, multiset<int>> mp;
    for (auto x : a) {
      if (mp[x-1].size()) {
        int len = *mp[x-1].begin();
        mp[x-1].erase(mp[x-1].begin());
        mp[x].insert(len+1);
      }
      else {
        mp[x].insert(1);
      }
    }
    bool ret = true;
    for (auto [key,val] : mp) {
      if (val.size()) {
        ret &= (*val.begin() >= 3);
      }
    }
    return ret;
  }
};