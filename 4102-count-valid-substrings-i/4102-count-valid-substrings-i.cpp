using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    long long countValidSubstrings(string s) {
        ll n = s.size(), ans = 0;
        vi idx;
        for (int i=0; i+2<n; i++) {
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
                idx.push_back(i);
            }
        }
        int sz = idx.size();
        for (int j=0; j<sz; j++) {
            auto i = idx[j];
            ll l = (j==0)?i+1:i-idx[j-1];
            ll r = n-i-2;
            ans += l * r;
        }
        ans = n*(n+1)/2 - ans;
        return ans;
    }
};