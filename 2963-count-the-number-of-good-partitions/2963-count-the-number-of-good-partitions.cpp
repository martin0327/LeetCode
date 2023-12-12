using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

class Solution {
public:
    ll mpow(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e&1) ret = (ret * b) % mod;
            b = (b * b) % mod;
            e >>= 1;
        }
        return ret;
    }
    
    int numberOfGoodPartitions(vector<int>& a) {
        ll n = a.size();
        map<ll,vi> mp;
        for (int i=0; i<n; i++) mp[a[i]].push_back(i);
        vector<pair<ll,ll>> b;
        for (auto &[k,v] : mp) {
            ll l = v.front(), r = v.back();
            b.push_back({l,r});
        }
        sort(b.begin(), b.end());
        vi st;
        for (auto [l,r] : b) {
            if (st.empty() || st.back() < l) st.push_back(r);
            else st.back() = max(st.back(), r);
        }
        ll sz = st.size();
        return mpow(2,sz-1);
    }
};  