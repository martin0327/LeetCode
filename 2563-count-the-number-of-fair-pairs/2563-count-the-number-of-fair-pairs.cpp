using ll = long long;

class Solution {
public:
    long long countFairPairs(vector<int>& a, int lo, int hi) {
        ll n = a.size(), ans = 0;
        sort(a.begin(), a.end());
        for (ll x  : a) {
            auto it1 = lower_bound(a.begin(),a.end(), lo-x);
            auto it2 = upper_bound(a.begin(),a.end(), hi-x);
            ans += it2 - it1; 
            if (lo <= 2*x && 2*x <= hi) ans--;
        }
        ans /= 2;
        return ans;
    }
};