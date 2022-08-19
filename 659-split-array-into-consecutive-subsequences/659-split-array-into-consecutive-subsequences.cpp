template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  bool isPossible(vector<int>& a) {
    map<int, min_pq<int>> mp;
    for (auto x : a) {
      if (mp[x-1].size()) {
        int len = mp[x-1].top();
        mp[x-1].pop();
        mp[x].push(len+1);
      }
      else {
        mp[x].push(1);
      }
    }
    bool ret = true;
    for (auto [key,val] : mp) {
      if (val.size()) {
        ret &= (val.top() >= 3);
      }
    }
    return ret;
  }
};