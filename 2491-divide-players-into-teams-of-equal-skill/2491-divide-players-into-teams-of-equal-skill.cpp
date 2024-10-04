using ll = long long;
class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        ll n = a.size();
        sort(a.begin(), a.end());
        ll t = a.back() + a.front();
        ll ans = 0;
        for (int i=0; i<n/2; i++) {
            ll x = a[i];
            ll y = a[n-1-i];
            if (x+y != t) return -1;
            ans += x * y;
        }
        return ans;
    }
};