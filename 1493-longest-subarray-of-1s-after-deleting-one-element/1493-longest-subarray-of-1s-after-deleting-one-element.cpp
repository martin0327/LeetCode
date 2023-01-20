using vi = vector<int>;
class Solution {
public:
  int longestSubarray(vector<int>& a) {
    int n = a.size();
    int i=0, j=0, cnt=0, ans=0;
    while (i<n) {
      if (cnt < 2 && j < n) cnt += (a[j++]==0);
      else cnt -= (a[i++]==0);
      if (cnt < 2) ans = max(ans, j-i-1); 
    }
    return ans;
  }
};