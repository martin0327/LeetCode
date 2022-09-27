using pii = pair<int,int>;
using vp = vector<pii>;

class Solution {
public:
  string pushDominoes(string s) {
    int n = s.size();

    vp rl;
    int idx = -1;
    for (int i=0; i<n; i++) {
      if (s[i] == 'R') {
        idx = i;
      }
      else if (s[i] == 'L') {
        if (idx==-1) continue;
        else {
          rl.push_back({idx,i});
          idx = -1;
        }
      }
    }
    
    int last = 0;
    string ret = s;
    for (auto [r,l] : rl) {
      bool rr = false;
      for (int i=last; i<r; i++) {
        if (rr) ret[i] = 'R';
        else if (s[i] == 'L') {
          for (int j=i-1; j>=last; j--) {
            if (s[j] == 'L') break;
            ret[j] = 'L';
          }
        }
        else if (s[i] == 'R') rr = true;
      }    
      int w = (l-r-1)/2;
      for (int i=1; i<=w; i++) {
        ret[r+i] = 'R';
      }
      for (int i=1; i<=w; i++) {
        ret[l-i] = 'L';
      }  
      last = l+1;
    }

    bool rr = false;
    for (int i=last; i<n; i++) {
      if (rr) ret[i] = 'R';
      else if (s[i] == 'L') {
        for (int j=i-1; j>=last; j--) {
          if (s[j] == 'L') break;
          ret[j] = 'L';
        }
      }
      else if (s[i] == 'R') rr = true;
    }
    return ret;
  }
};