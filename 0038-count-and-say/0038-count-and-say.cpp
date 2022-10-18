class Solution {
public:
  string countAndSay(int n) {
    if (n==1) return "1";
    string res = countAndSay(n-1);
    vector<pair<int,int>> a;
    for (auto c : res) {
      int x = c - '0';
      if (a.empty() || a.back().first != x) a.push_back({x,1});
      else a.back().second++;
    }
    string ret;
    for (auto [x,cnt] : a) {
      ret += cnt + '0';
      ret += x + '0';
    }
    return ret;
  }
};