using ll = long long;
const ll inf = 2e18;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& a) {
        map<ll,ll> mp;
        for (auto x : a) mp[x]++;
        queue<pair<ll,ll>> q;
        ll mx = 0, ans = 0;
        for (auto [x,cnt] : mp) {
            while (q.size()) {
                auto [y,val] = q.front();
                if (y < x-2) {
                    q.pop();
                    mx = max(mx, val);
                }
                else break;
            }
            ll val = mx + x*cnt;
            q.push({x,val});
            ans = max(ans, val);
        }
        return ans;
    }
};