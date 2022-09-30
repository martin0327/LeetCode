using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& a) {
    
    map<int, vi> mp;
    for (auto lrh : a) {
      int l = lrh[0];
      int r = lrh[1];
      int h = lrh[2];
      mp[l].push_back(h);
      mp[r].push_back(-h);
    }
    
    multiset<int> ms;
    vvi ans;
    for (auto &[k,v] : mp) {
      for (auto h : v) {
        if (h > 0) ms.insert(h);
        else ms.erase(ms.find(-h));
      }
      if (ms.empty()) {
        if (ans.empty() || ans.back()[1] != 0) {
          ans.push_back({k,0});
        }
      }
      else {
        if (ans.empty() || ans.back()[1] != *ms.rbegin()) {
          ans.push_back({k,*ms.rbegin()});
        }
      }
    }
    
    return ans;
  }
};    