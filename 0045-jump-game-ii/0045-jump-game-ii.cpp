using pii = pair<int,int>;
using vp = vector<pii>;
class Solution {
public:
  int jump(vector<int>& a) {
    int n = a.size();
    vector<int> b = {0}; // b[i] = i번 안에 갈 수 있는 가장 큰 index
    for (int i=0; i<n; i++) {
      auto it = lower_bound(b.begin(), b.end(), i);
      int cnt = it - b.begin();
      if (cnt==b.size()-1) {
        if (i+a[i] > b[cnt]) b.push_back(min(i+a[i],n-1));
      }
      else b[cnt+1] = max(b[cnt+1], min(i+a[i],n-1));
    }
    int ans;
    for (int i=0; i<b.size(); i++) {
      if (b[i]==n-1) {
        ans = i;
        break;
      } 
    }
    return ans;
  }
};