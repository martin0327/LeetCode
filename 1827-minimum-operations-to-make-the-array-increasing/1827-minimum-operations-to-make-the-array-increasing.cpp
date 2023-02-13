class Solution {
public:
  int minOperations(vector<int>& a) {
    int ans = 0, n = a.size();
    for (int i=0; i<n-1; i++) {
      if (a[i] >= a[i+1]) {
        int d = a[i] - a[i+1] + 1;
        a[i+1] += d;
        ans += d;
      }
    }
    return ans;
  }
};


