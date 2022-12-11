template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;


class Solution {
public:
  vector<int> maxPoints(vector<vector<int>>& a, vector<int>& queries) {
    using ll = long long;
    using vi = vector<ll>;
    using vvi = vector<vi>;
    using pii = pair<ll,ll>;
    using vp = vector<pii>;
    
    vi dr = {0,0,-1,1};
    vi dc = {-1,1,0,0};

    int q = queries.size();
    vp off(q);
    for (int i=0; i<q; i++) off[i] = {queries[i],i};
    sort(off.begin(), off.end());

    vector<int> ans(q);

    min_pq<tuple<int,int,int>> pq;
    int n = a.size();
    int m = a[0].size();

    int cnt = 0;
    vvi check(n, vi(m));
    

    pq.push({a[0][0],0,0});
    check[0][0] = 1;
    for (auto [lim,idx] : off) {
      if (pq.empty()) {
        ans[idx] = cnt;
        continue;
      }
      auto [val,rr,cc] = pq.top();
      if (lim > val) {
        while (pq.size()) {
          auto [x,r,c] = pq.top();
          if (lim <= x) break;
          pq.pop();
          cnt++;
          for (int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= n) continue;
            if (nc < 0 || nc >= m) continue;
            if (check[nr][nc]) continue;
            pq.push({a[nr][nc],nr,nc});
            check[nr][nc] = 1;
          }
        }
      }      
      ans[idx] = cnt;
    }
    return ans;
  }
};