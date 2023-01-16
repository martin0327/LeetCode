using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
    int n = a.size();
    vi l, r;
    for (auto lr : a) {
      l.push_back(lr[0]);
      r.push_back(lr[1]);
    }
    auto it1 = lower_bound(r.begin(), r.end(), b[0]);
    auto it2 = upper_bound(l.begin(), l.end(), b[1]);
    if (it1 == r.end()) {
      a.push_back(b);
      return a;
    }
    if (it2 == l.begin()) {
      a.insert(a.begin(), b);
      return a;
    }
    int ll = it1 - r.begin();
    int rr = prev(it2) - l.begin();

    vvi ret;
    for (int i=0; i<ll; i++) ret.push_back(a[i]);
    ret.push_back({min(b[0],a[ll][0]), max(b[1],a[rr][1])});
    for (int i=rr+1; i<n; i++) ret.push_back(a[i]);
    return ret;
  }
};