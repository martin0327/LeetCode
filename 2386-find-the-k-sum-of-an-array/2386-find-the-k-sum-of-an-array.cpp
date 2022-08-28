using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;

class Solution {
public:
    long long kSum(vector<int>& a, int k) {
        ll n = a.size();
          vi b;
          ll cnt_0 = 0;
          ll tot = 0;
          for (auto x : a) {
            if (x>0) tot += x;
            if (x!=0) b.push_back(abs(x)); 
            else cnt_0++;
          }
          
          multiset<pii> pq;
          ll m = b.size();
          sort(b.begin(), b.end());
          for (int i=0; i<m; i++) {
            pq.insert({b[i],i});
          }
          
          ll cnt = (1<<cnt_0);
          ll ans = tot;
          
          if (cnt >= k) return ans;
          
          while (pq.size()) {
            auto [x,i] = *pq.begin();
            pq.erase(pq.begin());
            cnt += (1<<cnt_0);
            ans = tot - x;
            if (cnt >= k) return ans;
            for (int j=i+1; j<m; j++) {
              if (pq.size() < 3000) pq.insert({x+b[j], j});
              else {
                auto [y,_] = *prev(pq.end());
                if (x+b[j] < y) {
                  pq.erase(prev(pq.end()));
                  pq.insert({x+b[j],j});
                }
                else break;
              }
            }
          }

        return ans;          
    }
};