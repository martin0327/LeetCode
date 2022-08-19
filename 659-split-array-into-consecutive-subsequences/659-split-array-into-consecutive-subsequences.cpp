class Solution {
public:
  bool isPossible(vector<int>& a) {
    vector<multiset<int>> b(2002);
    for (auto &x : a) x += 1001;
    for (auto x : a) {
      if (b[x-1].size()) {
        int len = *b[x-1].begin();
        b[x-1].erase(b[x-1].begin());
        b[x].insert(len+1);
      }
      else {
        b[x].insert(1);
      }
    }
    bool ret = true;
    for (int i=0; i<2001; i++) {
      if (b[i].size()) {
        ret &= (*b[i].begin()>=3);
      }
    }

    return ret;
  }
};