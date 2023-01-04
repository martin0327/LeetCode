class Solution {
public:
  int minimumRounds(vector<int>& a) {
    map<int,int> mp;
    for (auto x : a) mp[x]++;
    int ans = 0;
    for (auto [k,v] : mp) {
      if (v==1) return -1;
      ans += (v+2) / 3;
    }
    return ans;
  }
};