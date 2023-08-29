class Solution {
public:
    bool canCross(vector<int>& a) {
        int n = a.size();
        using ll = long long;
        using vi = vector<ll>;
        set<ll> s;
        for (auto x : a) s.insert(x);
        map<ll,set<ll>> mp;
        mp[0].insert(0);
        for (ll i=0; i<n; i++) {
            for (auto j : mp[a[i]]) {
                for (int d=-1; d<=1; d++) {
                    ll nj = j + d;
                    ll x = a[i] + nj;
                    if (nj > 0 && s.count(a[i]+nj)) {
                        mp[x].insert(nj);
                    }
                }
            }
        }
        return !mp[a.back()].empty(); 
    }
};