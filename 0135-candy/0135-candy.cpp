template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using vi = vector<int>;
using pii = pair<int,int>;
using vp = vector<pii>;
class Solution {
public:
  int candy(vector<int>& a) {
    int n = a.size();
    vp b(n);
    for (int i=0; i<n; i++) b[i] = {a[i],i};
    sort(b.begin(), b.end());
    vi c(n);
    for (auto [x,i] : b) {
      int temp = 1;
      if (i>0 && c[i-1]) {
        if (a[i] > a[i-1]) temp = c[i-1]+1;
      }
      if (i<n-1 && c[i+1]) {
        if (a[i] > a[i+1]) temp = max(temp, c[i+1]+1);
      }
      c[i] = temp;
    }
    int ans = 0;
    for (auto x : c) ans += x;
    return ans;
  }
};