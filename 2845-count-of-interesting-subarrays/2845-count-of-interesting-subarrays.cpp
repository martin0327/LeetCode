using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    ll sm(ll x, ll m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }
    
    long long countInterestingSubarrays(vector<int>& a, int m, int k) {
        int n = a.size();
        vi pre(n+1);
        for (int i=0; i<n; i++) pre[i+1] = pre[i] + (a[i]%m==k);
        ll ans = 0;
        map<ll,ll> mp;
        for (auto x : pre) {
            ans += mp[sm(x-k,m)];
            mp[x%m]++;
        }
        return ans;
    }
};