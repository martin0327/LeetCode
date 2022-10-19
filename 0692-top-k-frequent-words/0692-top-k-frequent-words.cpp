class Solution {
public:
  vector<string> topKFrequent(vector<string>& a, int k) {
    map<string,int> mp;
    for (auto x : a) mp[x]++;
    vector<pair<int,string>> b;
    for (auto &[k,v] : mp) {
      b.push_back({-v,k});
    }
    sort(b.begin(), b.end());
    vector<string> ans;
    for (int i=0; i<k; i++) {
      auto [cnt,x] = b[i];
      ans.push_back(x);
    }
    return ans;
  }
};