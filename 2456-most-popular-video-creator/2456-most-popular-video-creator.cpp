class Solution {
public:
  vector<vector<string>> mostPopularCreator(vector<string>& a, vector<string>& b, vector<int>& c) {
    int n = a.size();
    using ll = long long;
    map<string,ll> mp;
    for (int i=0; i<n; i++) {
      mp[a[i]] += c[i];
    }
    ll max_p = 0;
    for (auto [k,v] : mp) {
      max_p = max(max_p, v);
    }
    map<string,vector<pair<ll,string>>> mp2;
    for (int i=0; i<n; i++) {
      if (mp[a[i]]==max_p) {
        mp2[a[i]].push_back({-c[i],b[i]});
      }
    }
    vector<vector<string>> ret;
    for (auto &[k,v] : mp2) {
      sort(v.begin(), v.end());
      auto [w,s] = v[0];
      ret.push_back({k,s});
    }
    return ret;
  }
};