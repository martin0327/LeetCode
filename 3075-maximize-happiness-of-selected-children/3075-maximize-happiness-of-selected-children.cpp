using ll = long long;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        ll ans = 0;
        sort(a.rbegin(), a.rend());
        for (int i=0; i<k; i++) {
            ans += max(0, a[i]-i);
        }        
        return ans;
    }
}; 