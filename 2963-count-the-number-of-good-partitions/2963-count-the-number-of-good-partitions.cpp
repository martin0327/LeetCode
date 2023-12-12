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
        vector<pair<ll,ll>> b, st;
        for (auto &[k,v] : mp) {
            ll l = v.front(), r = v.back();
            b.push_back({l,r});
        }
        sort(b.begin(), b.end());
        for (auto [l,r] : b) {
            if (st.empty()) st.push_back({l,r});
            else {
                auto [l1,r1] = st.back();
                if (l < r1) {
                    st.pop_back();
                    ll l2 = min(l,l1);
                    ll r2 = max(r,r1);
                    st.push_back({l2,r2});
                }
                else st.push_back({l,r});
            }
        }
        ll sz = st.size();
        cout << sz << endl;
        return mpow(2,sz-1);
       
    }
};