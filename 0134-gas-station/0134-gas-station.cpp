using vi = vector<int>;
class Solution {
public:
    int canCompleteCircuit(vector<int>& a, vector<int>& b) {
      int n = a.size();
      vi c(n);
      for (int i=0; i<n; i++) {
        c[i] = a[i] - b[i];
      }
      vi pre(n);
      pre[0] = c[0];
      for (int i=1; i<n; i++) pre[i] = pre[i-1] + c[i];
      if (pre[n-1] >= 0) {
        int m = 1e9;
        int idx = -1;
        for (int i=0; i<n; i++) {
          if (pre[i] < m) {
            m = pre[i];
            idx = i;
          }
        }
        return (idx+1) % n;
      }
      else {
        return -1;
      }
    }
};