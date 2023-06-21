using ll = long long;
ll sum(vector<int> &b) {
    ll ret = 0;
    for (auto &x : b) ret += x;
    return ret;
}
class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b) {
        
    ll n = a.size();
    map<ll,ll> mp;
    for (int i=0; i<n; i++) {
        mp[a[i]] += b[i];
    }

    ll l = mp.begin()->first;
    ll r = mp.rbegin()->first;

    ll ans = 0;
    for (auto [k,v] : mp) {
        ans += abs(k-l) * v;
    }

    ll cur = ans;
    ll left = mp.begin()->second;
    ll right = sum(b) - left;

    for (int i=l+1; i<=r; i++) {
        cur += left;
        cur -= right;
        ans = min(ans, cur);
        if (mp.count(i)) {
          left += mp[i];
          right -= mp[i];
        }

    }
    return ans;


    }
};