class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      vector<int> x(26);
      int n = s1.size();
      int m = s2.size();
      if (n > m) return false;
      
      for (int i=0; i<n; i++) {
        x[s1[i] - 'a']++;
      }
      
      vector<int> y(26);
      for (int i=0; i<n; i++) {
        y[s2[i] - 'a']++;
      }
      if (x==y) return true;
      for (int i=1; i+n-1<m; i++) {
        y[s2[i-1] - 'a']--;
        y[s2[i+n-1] - 'a']++;
        if (x==y) return true;
      }      
      
      return false;
    }
};