class Solution {
public:
  int n;
  string s;
  map<int,vector<char>> mp;
  vector<string> ret;
    
  void f(int i, string cur) {
    if (i==n) {
      ret.push_back(cur);
      return;
    }
    for (auto c : mp[s[i] - '0']) {
      string temp = cur + c;
      f(i+1, cur + c);
    }
  } 
  
  vector<string> letterCombinations(string digits) {
    s = digits;
    n = s.size();
        
    int val = 0;
    for (int i=2; i<=9; i++) {
      int sz = 3;
      if (i==7 || i==9) sz = 4;
      for (int j=0; j<sz; j++) {
        mp[i].push_back('a' + val++);
      }
    }    
    
    ret.clear();
    
    if (n==0) return ret;
    
    f(0, "");
    
    return ret;
  }
};