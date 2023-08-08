class Solution {
public:
  int search(vector<int>& a, int t) {
    int n = a.size();
    int lo = 0, hi = n-1;
    int idx = -1;
    while (lo <= hi) {
      int mid = (lo+hi) / 2;
      if (a[mid] >= a[0]) {
        idx = mid;
        lo = mid + 1;
      }
      else hi = mid - 1;
    }
    idx = (idx+1)%n;
    lo = 0;
    hi = n-1;
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      int i = (mid+idx)%n;
      if (a[i] == t) return i;
      else if (a[i]<t) lo = mid + 1;
      else hi = mid - 1;
    }
    return -1;
  }
};