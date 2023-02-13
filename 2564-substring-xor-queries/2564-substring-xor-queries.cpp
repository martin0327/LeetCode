class Solution {
public:
  vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& qr) {
    map<int,vector<int>> mp;
    int n = s.size();
    for (int i=0; i<n; i++) {
      if (s[i]=='0') {
        if (!mp.count(0)) mp[0] = {i,i};
      }
      else {
        int x = 0;
        for (int j=i; j<min(i+30,n); j++) {
          x <<= 1;
          x += (s[j]=='1');
          if (!mp.count(x)) mp[x] = {i,j};
        }
      }
    }
    vector<vector<int>> ret;
    for (auto q : qr) {
      int x = q[0] ^ q[1];
      if (mp.count(x)) ret.push_back(mp[x]);
      else ret.push_back({-1,-1});
    }
    return ret;
  }
};