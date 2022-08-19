template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  bool isPossible(vector<int>& a) {
    unordered_map<int, deque<int>> mp;
    for (auto x : a) {
      if (mp[x-1].size()) {
        int len = mp[x-1].front();
        mp[x-1].pop_front();
        mp[x].push_back(len+1);
      }
      else {
        mp[x].push_front(1);
      }
    }
    
    bool ret = true;
    for (auto [key,val] : mp) {
      if (val.size()) {
        ret &= (val.front() >= 3);
      }
    }
    return ret;
  }
};