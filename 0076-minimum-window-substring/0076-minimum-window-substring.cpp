class Solution {
public:
    string minWindow(string s, string t) {
      int n = s.size();
      map<int,int> mp1, mp2;
      for (auto c : t) mp2[c]++;
      int sz = mp2.size();
      int i=0, j=0, cnt=0, ii=-1, jj=-1;;
      int min_len = 1e9;
      string ans;
      while (i<n) {
        if (cnt<sz && j<n) {
          if (mp2.count(s[j]) && ++mp1[s[j]] == mp2[s[j]]) cnt++;
          j++;
        }
        else {
          if (mp2.count(s[i]) && --mp1[s[i]] < mp2[s[i]]) cnt--;
          i++;
        }
        if (cnt==sz) {
          if (j-i < min_len) {
            min_len = j-i;
            ii = i;
            jj = j;
          }
        }
      }
      if (ii != -1) ans = s.substr(ii,jj-ii);
      return ans;
    }
}; 