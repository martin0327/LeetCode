class Solution {
public:
  set<string> ss;
  map<string,bool> mp;

  bool f(string s) {
    if (mp.count(s)) return mp[s];
    bool ret = false;
    int n = s.size();
    for (int i=1; i<n; i++) {
      if (ss.count(s.substr(0,i))) {
        string t = s.substr(i,n-i);
        if (ret |= ss.count(t) | f(t)) break;
      }
    }
    return mp[s] = ret;
  }
  
  vector<string> findAllConcatenatedWordsInADict(vector<string>& a) {
    ss = set<string>(a.begin(), a.end());
    vector<string> ret;
    for (auto s : a) if (f(s)) ret.push_back(s);
    return ret;
  }
};