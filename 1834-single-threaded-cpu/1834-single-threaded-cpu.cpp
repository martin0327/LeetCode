template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& t) {
    int n = t.size();
    for (int i=0; i<n; i++) t[i].push_back(i);
    sort(t.rbegin(), t.rend());
    
    ll cur = 0;
    min_pq<pii> pq;
    vi ans;

    while (t.size() || pq.size()) {
      if (pq.empty()) cur = max(cur, (ll) t.back()[0]);
      while (t.size() && t.back()[0] <= cur) {
        auto x = t.back();
        pq.emplace(x[1],x[2]);
        t.pop_back();
      }

      if (pq.size()) {
        auto [p,i] = pq.top();
        pq.pop();
        cur += p;
        ans.push_back(i);
      }
    }
    return ans;
  }
};