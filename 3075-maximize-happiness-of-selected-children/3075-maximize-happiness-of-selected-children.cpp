using ll = long long;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        ll n = a.size(), ans = 0;
        sort(a.rbegin(), a.rend());
        for (ll i=0; i<k; i++) {
            ans += max(0ll, a[i]-i);
        }        
        return ans;
    }
};