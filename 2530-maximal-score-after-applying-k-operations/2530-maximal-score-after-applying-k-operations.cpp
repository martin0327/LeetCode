using ll = long long;
class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        priority_queue<ll> pq;
        for (auto x : a) pq.push(x);
        ll ans = 0;
        while (pq.size() && k--) {
            ll x = pq.top();
            pq.pop();
            ans += x;
            pq.push((x+2)/3);
        }
        return ans;
    }
};