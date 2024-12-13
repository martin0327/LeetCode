using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
class Solution {
public:
    long long findScore(vector<int>& a) {
        ll ans = 0, n = a.size();
        vi check(n);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i=0; i<n; i++) {
            pq.push({a[i],i});
        }
        while (pq.size()) {
            auto [x,i] = pq.top();
            pq.pop();
            if (!check[i]) {
                ans += x;
                check[i] = 1;
                if (i > 0) check[i-1] = 1;
                if (i+1 < n) check[i+1] = 1;
            }
        }
        return ans;
    }
};