class Solution {
public:
  int minimumMoves(string s) {
    int n = s.size();
    int ans = 0;
    for (int i=0; i<n; i++) {
      if (s[i] == 'X') {
        ans++;
        for (int j=i+1; j<min(n,i+3); j++) {
          s[j] = 'O';
        }
      }
    }
    return ans;
  }
};