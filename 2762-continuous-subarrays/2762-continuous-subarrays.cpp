using ll = long long;
class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
        ll n = a.size(), ans = 0;
        multiset<ll> s;
        for (int i=0,j=0; j<n; j++) {
            s.insert(a[j]);
            while (s.size()) {
                auto x = *s.begin();
                auto y = *s.rbegin();
                if (y-x > 2) {
                    s.erase(s.find(a[i++]));
                }
                else break;
            }
            ans += j-i+1;
        }
        return ans;
    }
};