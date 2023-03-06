class Solution {
public:
  int findKthPositive(vector<int>& a, int k) {
    int n = a.size(), i = 0, j = 1, cnt = 0;
    while (cnt < k) {
      if (i < n && a[i]==j) {
        i++;
        j++;
      }
      else {
        cnt++;
        j++;
      }
    }
    return j-1;
  }
};