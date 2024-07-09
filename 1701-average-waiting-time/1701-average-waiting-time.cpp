using ll = long long;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        ll p = 0, cum = 0;
        for (auto xy : a) {
            ll x = xy[0], y = xy[1];
            ll t = max(x,p) + y;
            cum += t - x;
            p = t;
        }
        double ans = cum;
        ans /= (ll) a.size();
        return ans;
    }
};