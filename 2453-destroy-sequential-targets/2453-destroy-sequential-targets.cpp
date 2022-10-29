class Solution {
public:
  int destroyTargets(vector<int>& a, int sp) {
    map<int,int> mp;
    for (auto x : a) {
      mp[x%sp]++;
    }
    int max_cnt = 0;
    for (auto [k,v] : mp) {
      max_cnt = max(max_cnt, v);
    }
    set<int> rem;
    for (auto [k,v] : mp) {
      if (v==max_cnt) rem.insert(k);
    }
    int ans = 1e9;
    for (auto x : a) {
      if (rem.count(x%sp)) ans = min(ans, x);
    }
    return ans;
  }
};