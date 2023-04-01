using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& a, int k) {
        int n = a.size();
        int d = gcd(n,k);
        map<int,vi> mp;
        for (int i=0; i<n; i++) mp[i%d].push_back(a[i]);

        ll ans = 0;
        for (auto &[r,b] : mp) {
            sort(b.begin(), b.end());
            int sz = b.size();
            int idx = sz / 2;
            for (auto x : b) {
                ans += abs(x-b[idx]);
            }
        }
        return ans;
    }
};