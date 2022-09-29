class Solution {
public:
  vector<int> findClosestElements(vector<int>& a, int k, int x) {
    int n = a.size();
    int l = -1, r = -1;
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it != a.end()) l = it - a.begin();
    it = upper_bound(a.begin(), a.end(), x);
    if (it != a.begin()) r = prev(it) - a.begin();

    vector<int> ret;
    if (l == -1) {
      for (int i=0; i<k; i++) ret.push_back(a[r--]);
      reverse(ret.begin(), ret.end());
    }
    else if (r == -1) {
      for (int i=0; i<k; i++) ret.push_back(a[l++]);
    }
    else {
      if (r < l) swap (l,r);
      else r = l+1;
      vector<int> b;
      for (int i=0; i<k; i++) {
        if (l >= 0 && r < n) {
          int d1 = abs(x-a[l]);
          int d2 = abs(x-a[r]);
          if (d1<=d2) ret.push_back(a[l--]);
          else b.push_back(a[r++]);
        }
        else if (l >= 0) ret.push_back(a[l--]);
        else b.push_back(a[r++]);
      }
      reverse(ret.begin(), ret.end());
      for (auto &x : b) ret.push_back(x);
    }
    return ret;
  }
}; 