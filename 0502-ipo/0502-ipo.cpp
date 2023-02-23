using pii = pair<int,int>;
class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<pii> ba(n);
    for (int i=0; i<n; i++) ba[i] = {b[i],a[i]};
    sort(ba.rbegin(), ba.rend());
    priority_queue<int> pq;
    while (k--) {
      while (ba.size()) {
        auto [y,x] = ba.back();
        if (y <= w) {
          ba.pop_back();
          pq.push(x);
        }
        else break;
      }
      if (pq.size()) {
        w += pq.top();
        pq.pop();
      }
      else break;
    }
    return w;
  }
};