class Solution {
public:
  vector<int> addToArrayForm(vector<int>& a, int k) {
    vector<int> b, ret;
    for (auto c : to_string(k)) b.push_back(c - '0');
    int x = 0;
    while (a.size() && b.size()) {
      int s = x + a.back() + b.back();
      a.pop_back(); b.pop_back();
      ret.push_back(s % 10);
      x = s / 10;
    }
    if (a.empty()) swap(a, b);
    while (a.size()) {
      int s = x + a.back();
      a.pop_back();
      ret.push_back(s % 10);
      x = s / 10;
    }
    if (x) ret.push_back(x);      
    reverse(ret.begin(), ret.end());    
    return ret;
  }
};