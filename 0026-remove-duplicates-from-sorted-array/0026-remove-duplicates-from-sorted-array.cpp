class Solution {
public:
  int removeDuplicates(vector<int>& a) {
    int n = a.size(), idx = 1;
    for (int i=0; i<n-1; i++) {
      if (a[i] < a[i+1]) a[idx++] = a[i+1];
    }
    return idx;
  }
};        