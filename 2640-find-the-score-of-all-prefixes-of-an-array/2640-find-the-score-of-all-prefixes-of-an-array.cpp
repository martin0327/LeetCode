using ll = long long;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& a) {
        ll mx = 0;
        vector<ll> ans;
        for (ll x : a) {
            mx = max(mx, x);
            if (ans.empty()) ans.push_back(x+mx);
            else ans.push_back(ans.back()+x+mx);
        }
        return ans;
    }
};