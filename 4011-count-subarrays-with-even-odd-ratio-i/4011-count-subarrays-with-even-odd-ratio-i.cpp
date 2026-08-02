using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int countRatioSubarrays(vector<int>& aa, ll a, ll b) {
        vi c(aa.begin(), aa.end());
        ll n = c.size(), ans = 0;
        for (int i=0; i<n; i++) {
            ll x = 0, y = 0;
            for (int j=i; j<n; j++) {
                if (c[j]&1) y++;
                else x++;
                if (y > 0 && x*b <= y*a) ans++;
            }
        }
        return ans;
    }
};