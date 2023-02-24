using ll = long long;
class Solution {
public:
  int minimumDeviation(vector<int>& a) {
    int n = a.size();
    multiset<ll> s;
    for (int i=0; i<n; i++) {
      if (a[i]&1) s.insert(2*a[i]);
      else s.insert(a[i]);
    }
    ll ans = 2e9, cur_max = 2e9;
    bool done = false;
    while (s.size()>1) {
      // debug(ms);
      ll hi = *prev(s.end()), lo = *s.begin();
      if (!done) cur_max = min(cur_max, hi);
      ans = min(ans, cur_max - lo);
      if (hi%2==0) {
        s.erase(s.find(hi));
        s.insert(hi/2);        
      }      
      else {
        s.erase(s.find(hi));
        done = true;
      }
    }
    return ans;    
  }
};